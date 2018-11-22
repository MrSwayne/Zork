#include "controller.h"
#include "logger.h"

#include <QDebug>
#include <iostream>

Controller::Controller(Model *model, View *view) : model(model), view(view)
{
    //object communication
    connect(model, SIGNAL(updateRoom()), this, SLOT(updateView()));
    connect(view, SIGNAL(updateRoom(int)), this, SLOT(updateRoom(int)));
    connect(view, SIGNAL(updateCurrentRoomItems(int)), this, SLOT(updateRoomItems(int)));
    connect(view, SIGNAL(updateCurrentPlayerItems(int)), this, SLOT(updatePlayerItems(int)));
    connect(view, SIGNAL(attackEnemy()), this, SLOT(attackEnemy()));
    model->setCurrentRoom();
}

Controller::~Controller()
{
    delete model;
    delete view;
}

void Controller::updateRoom(int num)
{
    model->setCurrentRoom(num);
}

void Controller::updateView()
{
    //controls the updating of what is displayed
    view->updateRoomButtons(model->getCurrentRoom()->getExits(), model->getCurrentRoom()->getRoomNumber());
    view->populateList(model->getCurrentRoom()->getRoomItems(), model->getPlayer()->getPlayerItems());
    view->disableAttack(model->getCurrentRoom()->isEnemyDead());
}


void Controller::updatePlayerItems(int num)
{
    //adds item to play via operator overload
    *model->getPlayer() + model->getCurrentRoom()->removeItem(num);
    updateView();
}

void Controller::updateRoomItems(int num)
{
    model->getCurrentRoom()->addRoomItem(*model->getPlayer() - num);
    updateView();
}

void Controller::attackEnemy()
{
    model->getCurrentRoom()->playerFight(model->getPlayer());
    if(model->getPlayer()->getHealth() < 60) view->updateHealth();
    updateView();
    QString word = "Player attack";
    Logger::log(*(model->getPlayer()),word);
}
