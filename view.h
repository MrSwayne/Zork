#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QLabel>
#include <QPixmap>
#include <QListWidget>
#include <vector>
#include "item.h"

class View : public QWidget
{
    Q_OBJECT
public:
    View(QWidget* parent = 0);
    ~View();
    void updateRoomButtons(const unsigned char exits, int room);
    void populateList(const std::vector<Item*>& room_items, const std::vector<Item*>& player_items);
    void disableAttack(bool dead);
    void updateHealth();

private:
    QSignalMapper signal_mapper;
    QLabel *background_label, *enemy_label, *player_label;
    QPixmap *background_images[9];
    QMovie *enemy_image, *hero_image, *dead;
    QListWidget *room_item_display, *player_item_display;
    QPushButton *buttons[4], *drop_button, *take_button, *attack_button;
    void createWidgets();
    void setWidgetPos();

private slots:
    void updateRoomItems();
    void updatePlayerItems();

signals:
    void updateRoom(int);
    void updateCurrentRoomItems(int);
    void updateCurrentPlayerItems(int);
    void attackEnemy();
};

#endif // MAINWINDOW_H
