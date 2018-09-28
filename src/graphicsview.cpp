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




void GraphicsView::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
    }

    this->player->keyPress(event);
}

void GraphicsView::keyReleaseEvent(QKeyEvent *event) {
    this->player->keyRelease(event);
}


void GraphicsView::mousePressEvent(QMouseEvent *click) {
    /*
    std::cout << "click" << std::endl;
    QPoint origin = this->mapFromGlobal(QCursor::pos());
    QPointF relativeOrigin = this->mapToScene(origin);
    player->move(relativeOrigin);
    */
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
