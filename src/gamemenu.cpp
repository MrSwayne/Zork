#include "gamemenu.h"
#include "zork.h"
#include "mainwindow.h"
GameMenu::GameMenu(std::string name, IPushCallBack *ipcb) : Menu(name, ipcb)
{

}

void GameMenu::setup() {
    game = new Zork(this);
    game->run();
}

void GameMenu::destroy() {
    game->destroy();
}

void GameMenu::handlePushButtons() {
}
