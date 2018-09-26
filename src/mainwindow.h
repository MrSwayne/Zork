#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handlePlayButton();
    void handleLeaderboardsButton();
    void handleSettingsButton();

private:
    QMediaPlayer *musicPlayer = nullptr;
    QWidget *container = nullptr;
    QGridLayout *layout = nullptr;
    int HEIGHT;
    int WIDTH;
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
    void loadMainMenu();
    void loadGame();
};

#endif // MAINWINDOW_H
