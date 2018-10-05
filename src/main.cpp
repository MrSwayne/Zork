#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "config.h"

int main(int argc, char *argv[])
{
    Config *cfg = new Config();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
