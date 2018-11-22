#ifndef STARTMENU_H
#define STARTMENU_H

#include "menu.h"
#include <QWidget>
#include <QMediaPlayer>
#include <QGridLayout>

class StartMenu : public Menu
{
    Q_OBJECT
public:
    explicit StartMenu(std::string name, IPushCallBack *ipcb = nullptr);
    void setup();
    void destroy();
private:
    QMediaPlaylist *playlist= nullptr;
    QMediaPlayer *musicPlayer = nullptr;
    QGridLayout *layout = nullptr;
signals:

private slots:
    void handlePushButtons();
};

#endif // STARTMENU_H
