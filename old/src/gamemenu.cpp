#include "gamemenu.h"
#include "zork.h"
#include "mainwindow.h"
GameMenu::GameMenu(std::string name, QApplication *app, IPushCallBack *ipcb) : Menu(name, ipcb)
{
    this->app = app;
}

void GameMenu::setup() {
    game = new Zork(app, this);
    game->run();
}

void GameMenu::destroy() {
    game->destroy();
}

void GameMenu::handlePushButtons() {
}
