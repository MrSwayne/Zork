#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMediaPlayer>
#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int getHeight();
    int getWidth();
    ~MainWindow();

private slots:
    void handlePlayButton();
    void handleLeaderboardsButton();
    void handleSettingsButton();

private:
    QMediaPlayer *musicPlayer = nullptr;
    QWidget *container = nullptr;
    QGridLayout *layout = nullptr;
    Player *player = nullptr;
    int HEIGHT;
    int WIDTH;
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
    void loadMainMenu();
    void loadGame();
    void init();
};

#endif // MAINWINDOW_H
