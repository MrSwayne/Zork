#ifndef ZORK_H
#define ZORK_H

#include "mainwindow.h"

class Zork
{
public:
    Zork(MainWindow *w, QWidget *container);

private:
    MainWindow *window;
    QMediaPlayer *musicPlayer;
    Player *player;
    void setup(QWidget *container);

};

#endif // ZORK_H
