#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QCloseEvent>
#include <iostream>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "graphicsview.h"
#include "zork.h"
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

    //    this->showMaximized();
    this->setWindowTitle(TITLE);

    init();
}

void MainWindow::init() {

    loadMainMenu();
}

int MainWindow::getWidth() {
    return WIDTH;
}

int MainWindow::getHeight() {
    return HEIGHT;
}

void MainWindow::loadMainMenu() {
    delete container;
    delete musicPlayer;

    #if MUSIC == 1
    playlist=new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile(PATH + "/res/audio/main.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    musicPlayer = new QMediaPlayer;
    musicPlayer->setPlaylist(playlist);
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

//https://stackoverflow.com/questions/17480662/add-an-image-to-certain-position-in-qgraphicsscene

void MainWindow::loadGame() {
    delete container;
    delete musicPlayer;
    delete player;
    std::cout << "loading game screen" << std::endl;

    container = new QWidget();
    Zork *game = new Zork(this, container);
    game->run();

    setCentralWidget(container);
}

void MainWindow::handlePlayButton() {
    std::cout << "Play Button pressed"
                 "" << std::endl;
    loadGame();
}

void MainWindow::handleLeaderboardsButton() {
    std::cout << "Leaderboards button pressed" << std::endl;
}

void MainWindow::handleSettingsButton() {
    std::cout << "Settings button pressed" << std::endl;
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
