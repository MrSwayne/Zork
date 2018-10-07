#ifndef ZORK_H
#define ZORK_H

#include "mainwindow.h"
#include "graphicsview.h"
#include "Room.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

class Zork
{
public:
    Zork(MainWindow *w, QWidget *container);
    void run();

private:
    MainWindow *window = nullptr;
    QMediaPlaylist *playlist= nullptr;
    QMediaPlayer *musicPlayer = nullptr;
    Player *player = nullptr;
    QGraphicsScene *scene = nullptr;
    GraphicsView *gameView = nullptr;
    QGraphicsView *mapView = nullptr;
    QGraphicsView *inventoryView = nullptr;
    Room *crntRoom = nullptr;
    bool gameOver = false;
    int WIDTH;
    int HEIGHT;
    void setup(QWidget *container);
    void setupRooms();

};

#endif // ZORK_H
