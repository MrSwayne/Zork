#include "graphicsview.h"
#include <QGraphicsView>
#include <iostream>
#include <QMouseEvent>

GraphicsView::GraphicsView(QWidget *parent, Player *player, QGraphicsScene *scene) : QGraphicsView(parent) {
    this->scene = scene;
    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    if(player != nullptr) {
        this->player = player;
        scene->addItem(player);
    }
}


void GraphicsView::mousePressEvent(QMouseEvent *click) {
    std::cout << "click" << std::endl;
    QPoint p = click->pos();
    player->move(p);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event) {
    if(event->buttons()) {
        std::cout << "sadsa" << std::endl;
    }
}

/*
void GraphicsView::resizeEvent(QResizeEvent *event) {
    std::cout << "hello" << std::endl;
}*/
