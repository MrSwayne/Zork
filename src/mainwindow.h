#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "player.h"
#include <map>
#include "menu.h"
#include "ipushcallback.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IPushCallBack {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void notifyButtonPushed(QPushButton *b);
    ~MainWindow();

private:
    void setMenu(std::string menu);
    std::map<std::string, Menu*> menus;
    int HEIGHT;
    int WIDTH;
    Ui::MainWindow *ui;
    std::string crntMenu;
    void closeEvent(QCloseEvent *event);
    void init();
};

#endif // MAINWINDOW_H
