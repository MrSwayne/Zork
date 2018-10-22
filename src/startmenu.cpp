#include "startmenu.h"
#include <iostream>
#include <QtWidgets>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QSignalMapper>

#define PATH QDir::currentPath()

StartMenu::StartMenu(std::string name, IPushCallBack *ipcb) : Menu(name, ipcb)
{

}

void StartMenu::setup() {
    playlist=new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile(PATH + "/res/audio/main.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    musicPlayer = new QMediaPlayer;
    musicPlayer->setPlaylist(playlist);
    musicPlayer->setVolume(20);
    musicPlayer->play();

    std::cout << "Loading main menu" << std::endl;

    layout = new QGridLayout();
    this->setLayout(layout);

    QPushButton *playButton = new QPushButton("Play",this);
    connect(playButton, SIGNAL(released()), this, SLOT (handlePushButtons()));

    QPushButton *leaderboardButton = new QPushButton("Leaderboards",this);
    connect(leaderboardButton, SIGNAL(released()), this, SLOT (handlePushButtons()));

    QPushButton *settingsButton = new QPushButton("Settings", this);
    connect(settingsButton, SIGNAL(released()), this, SLOT (handlePushButtons()));

    QLabel *label = new QLabel(this);
    QPixmap pixmap(PATH + "/res/images/ZorkTitle.png");
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
}

void StartMenu::destroy() {
    delete layout;
    delete playlist;
    delete musicPlayer;
}

void StartMenu::handlePushButtons() {
    QPushButton *obj = (QPushButton*) QObject::sender();
    ipcb->notifyButtonPushed(obj);
}
