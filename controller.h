#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(Model *model, View *view);
    ~Controller();

private:
    Model *model;
    View *view;

private slots:
    void updateRoom(int);
    void updateView();
    void updatePlayerItems(int);
    void updateRoomItems(int);
    void attackEnemy();

signals:
    void disableAttack();
    void updateHealth();
};

#endif // CONTROLLER_H
