#include "gamemenu.h"

GameMenu::GameMenu(std::string name, IPushCallBack *ipcb) : Menu(name, ipcb)
{
}

#include <iostream>
void GameMenu::setup() {
    std::cout<<"well lad" << std::endl;
    game = new Zork();
    game->run();
}

void GameMenu::destroy() {
    //game->destroy();
}

void GameMenu::handlePushButtons() {
}
