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
#include "menu.h"
#include "ipushcallback.h"
#include "startmenu.h"
#include "gamemenu.h"
#include "config.h"

#define TITLE "Zork UL"
#define PATH QDir::currentPath()
#define MUSIC 1

MainWindow::MainWindow(Config &cfg, QApplication *app, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->app = app;

    //std::cout << PATH.toStdString() << std::endl;

    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    WIDTH = screen->geometry().width();
    HEIGHT = screen->geometry().height();

    this->setMinimumWidth(WIDTH / 2);
    this->setMinimumHeight(HEIGHT / 2);
    this->setMaximumWidth(WIDTH / 2);
    this->setMaximumHeight(HEIGHT / 2);

    //this->showMaximized();
    cout << cfg.get("title") << endl;
    this->setWindowTitle(QString::fromStdString(cfg.get("title")));

    init();
}

void MainWindow::notifyButtonPushed(QPushButton *btn) {
    std::string str = btn->text().toStdString();
    setMenu(str);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        menus[crntMenu]->destroy();
    }
}

void MainWindow::init() {
    Menu *startMenu = new StartMenu("Start", this);

    Menu *gameMenu = new GameMenu("Play", app, this);

    menus[startMenu->getName()] = startMenu;
    menus[gameMenu->getName()] = gameMenu;

    startMenu->setup();
    setCentralWidget(startMenu);
    crntMenu = startMenu->getName();
}



void MainWindow::setMenu(const std::string menu) {
    std::map<std::string, Menu*>::iterator it = menus.find(menu);
    if(it != menus.end()) {

        if(crntMenu != menu) {
            std::cout << "Destroying " << crntMenu << std::endl;
            menus[crntMenu]->destroy();
            std::cout << "setting up " << menu << std::endl;
            menus[menu]->setup();
            crntMenu = menu;
            setCentralWidget(menus[menu]);
        }
    }
    else {
      std::cerr << menu << " could not be found.";
      if(menus.size())
        setMenu(menus.begin()->first);
    }
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
