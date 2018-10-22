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
    Config *cfg = new Config();

    cfg->get("hello!");


    //Generic QT setup
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
