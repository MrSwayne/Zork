#include "menu.h"

#include "mainwindow.h"
Menu::Menu(std::string name, IPushCallBack *ipcb) : QWidget()
{
    this->name = name;
    this->ipcb = ipcb;
}

std::string Menu::getName() {
    return this->name;
}


