#include "zork.h"
#include "mainwindow.h"
#include "graphicsview.h"
#include "player.h"
#include <QtWidgets>
#include "Room.h"

#define PATH QDir::currentPath()
#define PLAYER_NAME "Jerry"


Zork::Zork(QWidget *container) {
    setup(container);
    WIDTH = container->width();
    HEIGHT = container->height();
}

void Zork::destroy() {
    delete musicPlayer;
    delete playlist;
    delete layout;
}

void Zork::run() {
    setupRooms();
    /*
    while(!gameOver) {
        //view->setScene
    }*/
}

void Zork::setupRooms() {    /*
    std::map<std::string, Menu*>::iterator it = menus.find(menu);
    if(it != menus.end())
        setCentralWidget(menus[menu]);
    else {
      std::cerr << "No menu of that name could be found.";
      setCentralWidget(menus[menus.begin()->first]);
    }*/
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;

    a = new Room("Forest", WIDTH, HEIGHT);
        //a->addItem(new Item("x", 1, 11));
        //a->addItem(new Item("y", 2, 22));
    b = new Room("b", WIDTH, HEIGHT);
        //b->addItem(new Item("xx", 3, 33));
        //b->addItem(new Item("yy", 4, 44));
    c = new Room("c", WIDTH, HEIGHT);
    d = new Room("d", WIDTH, HEIGHT);
    e = new Room("e", WIDTH, HEIGHT);
    f = new Room("f", WIDTH, HEIGHT);
    g = new Room("g", WIDTH, HEIGHT);
    h = new Room("h", WIDTH, HEIGHT);
    i = new Room("i", WIDTH, HEIGHT);

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);

    crntRoom = a;
}

void Zork::setup(QWidget *container) {
    gameOver = false;

    layout = new QGridLayout();
    container->setLayout(layout);

    playlist=new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile(PATH + "/res/audio/level.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    musicPlayer = new QMediaPlayer;
    musicPlayer->setPlaylist(playlist);
    musicPlayer->setVolume(20);
    musicPlayer->play();

    player = new Player(QString(PATH + "/res/images/sprites/player.png"), QString(PLAYER_NAME), QString("A man"), WIDTH / 2, HEIGHT / 2);

    scene = new QGraphicsScene(0,0,WIDTH,HEIGHT);
    scene->setSceneRect(0,0,1,1);
    scene->setBackgroundBrush(QBrush(QImage(PATH + "/res/images/room.jpg")));
    gameView = new GraphicsView(container, player, scene);

    QLabel *inventoryLabel = new QLabel(window->tr("Inventory"), container);
    inventoryLabel->setMaximumHeight(20);
    inventoryLabel->setMaximumWidth(80);

    QGraphicsScene *inventoryScene = new QGraphicsScene(0,0,50, 200);
    inventoryView = new GraphicsView(container, nullptr, inventoryScene);
    inventoryView->setMaximumHeight(200);
    inventoryView->setMaximumWidth(150);

    QLabel *mapLabel = new QLabel(window->tr("Map"), container);
    mapLabel->setMaximumHeight(20);
    mapLabel->setMaximumWidth(80);

    QGraphicsScene *mapScene = new QGraphicsScene(0,0,50,200);
    mapView = new GraphicsView(container, nullptr, mapScene);
    mapView->setMaximumHeight(200);
    mapView->setMaximumWidth(150);

    layout->addWidget(gameView, 0,0, 5, 1);
    layout->addWidget(inventoryLabel, 0,1);
    layout->addWidget(inventoryView, 1,1);
    layout->addWidget(mapLabel, 2, 1);
    layout->addWidget(mapView, 3, 1);
}
