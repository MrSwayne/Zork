#ifndef ZORK_H
#define ZORK_H

#include "QMainWindow"
#include "graphicsview.h"
#include "Room.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "mainwindow.h"
class Zork
{
public:
    Zork(QApplication *app, QWidget *container);
    void run();
    void destroy();
    void pause();

private:
    QApplication *app = nullptr;
    QMediaPlaylist *playlist= nullptr;
    QMediaPlayer *musicPlayer = nullptr;
    Player *player = nullptr;
    QGraphicsScene *scene = nullptr;
    GraphicsView *gameView = nullptr;
    QGraphicsView *mapView = nullptr;
    QGraphicsView *inventoryView = nullptr;
    Room *crntRoom = nullptr;
    QGridLayout *layout = nullptr;
    bool gameOver = false;
    QWidget *container;
    int WIDTH;
    int HEIGHT;
    void setup(QWidget *container);
    void setupRooms();
    enum eState {PLAY = 0, PAUSE, END};
    eState gameState = PLAY;
};

#endif // ZORK_H
