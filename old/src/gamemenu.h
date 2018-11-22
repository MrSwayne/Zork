#ifndef GAMEMENU_H
#define GAMEMENU_H
#include "menu.h"
#include <QWidget>
#include <QMainWindow>
#include "ipushcallback.h"
#include "zork.h"

class GameMenu : public Menu
{
    Q_OBJECT
public:
    explicit GameMenu(std::string name, QApplication *app, IPushCallBack *ipcb = nullptr);
    void setup();
    void destroy();
private:
    Zork *game = nullptr;
    QApplication *app;
signals:

private slots:
    void handlePushButtons();
};

#endif // GAMEMENU_H
