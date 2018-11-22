#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "config.h"
/*
 * @authors Adam Swayne & Caolan Mcdonagh
 *
 *
 *
*/

int main(int argc, char *argv[])
{

    //init config
    Config cfg = Config::getInstance();

    //Generic QT setup
    QApplication *a = new QApplication(argc, argv);
    MainWindow w(cfg, a);
    w.show();

    return a->exec();
}
