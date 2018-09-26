#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QCloseEvent>
#include <iostream>
#include <QMediaPlayer>
#include "GraphicsView.h"
#include <string.h>
#include "player.h"

#define TITLE "Zork UL"
#define PATH QDir::currentPath()
#define MUSIC 1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    WIDTH = screen->geometry().width();
    HEIGHT = screen->geometry().height();

    this->setMinimumWidth(WIDTH / 2);
    this->setMinimumHeight(HEIGHT / 2);
    this->setMaximumWidth(WIDTH / 2);
    this->setMaximumHeight(HEIGHT / 2);


   // this->showMaximized();
    this->setWindowTitle(TITLE);
    loadMainMenu();
}

//https://stackoverflow.com/questions/17480662/add-an-image-to-certain-position-in-qgraphicsscene

void MainWindow::loadGame() {
    std::cout << "loading game screen" << std::endl;

    container = new QWidget();
    layout = new QGridLayout();
    container->setLayout(layout);

    #if MUSIC == 1
        musicPlayer = new QMediaPlayer;
        musicPlayer->setMedia(QUrl::fromLocalFile(PATH + "/res/audio/level.mp3"));
        musicPlayer->setVolume(20);
        musicPlayer->play();
    #endif


        Player *player = new Player(QString(PATH + "/res/images/sprites/player.png"), QString::fromStdString("Jerry"), QString::fromStdString("A man"), WIDTH / 2, HEIGHT / 2);

    QGraphicsScene *scene = new QGraphicsScene(0,0,WIDTH,HEIGHT);
    GraphicsView *view = new GraphicsView(container, player, scene);

    scene->setSceneRect(0,0,1,1);
    scene->setBackgroundBrush(QBrush(QImage(PATH + "/res/images/room.jpg")));
    view->setScene(scene);

    QPixmap pixmap(WIDTH / 2,200);

    QGraphicsScene *scene2 = new QGraphicsScene(0,0,50, 200);
    GraphicsView *inventory = new GraphicsView(container, nullptr, scene2);

    QLabel *label = new QLabel(tr("Inventory"));

    inventory->setMaximumHeight(200);
    inventory->setMaximumWidth(150);

    layout->addWidget(view, 0,0, 40, 40);
    layout->addWidget(label, 0,41,4,1);
    layout->addWidget(inventory, 4,41,5, 1);
    setCentralWidget(container);
}

void MainWindow::handlePlayButton() {
    std::cout << "Play Button pressed"
                 "" << std::endl;
    delete container;
    delete musicPlayer;
    loadGame();
}

void MainWindow::handleLeaderboardsButton() {
    std::cout << "Leaderboards button pressed" << std::endl;
}

void MainWindow::handleSettingsButton() {
    std::cout << "Settings button pressed" << std::endl;
}

void MainWindow::loadMainMenu() {

    #if MUSIC == 1
        musicPlayer = new QMediaPlayer;
        musicPlayer->setMedia(QUrl::fromLocalFile(PATH + "/res/audio/main.mp3"));
        musicPlayer->setVolume(20);
        musicPlayer->play();
    #endif

    std::cout << "Loading main menu" << std::endl;

    container = new QWidget(this);

    QGridLayout *layout = new QGridLayout();
    container->setLayout(layout);

    QPushButton *playButton = new QPushButton("Play",container);
    connect(playButton, SIGNAL(released()), this, SLOT (handlePlayButton()));

    QPushButton *leaderboardButton = new QPushButton("Leaderboards",container);
    connect(leaderboardButton, SIGNAL(released()), this, SLOT (handleLeaderboardsButton()));

    QPushButton *settingsButton = new QPushButton("Settings", container);
    connect(settingsButton, SIGNAL(released()), this, SLOT (handleSettingsButton()));

    QLabel *label = new QLabel(container);
    QPixmap pixmap(PATH + "/res/images/logo.png");
    pixmap = pixmap.scaled(QSize(800, 200));
    label->setPixmap(pixmap);
    label->setMaximumWidth(pixmap.width());
    label->setMaximumHeight(pixmap.height());

    layout->setVerticalSpacing(50);
    layout->setMargin(0);
    layout->addWidget(label, 0, 0);
    layout->addWidget(playButton,1,0);
    layout->addWidget(leaderboardButton,2,0);
    layout->addWidget(settingsButton,3,0);

    setCentralWidget(container);
}

//If user presses the X button then a dialog opens up prompting them if they really want to quit
void MainWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, TITLE, tr("Are you sure you'd like to quit?\nAny unsaved progress will be lost!\n"),
    QMessageBox::No | QMessageBox::Yes,
    QMessageBox::Yes);

    if(resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
