#ifndef SPRITE_H
#define SPRITE_H

#include <QtWidgets>

class Sprite : public QGraphicsPixmapItem {
public:
    Sprite(QString path, QString desc, int spawnX, int spawnY);
    void setPath(QString path);
    void spawn();
    void draw();

private:
    QString desc;
    QPixmap *pixmap;
    int x;
    int y;
};

#endif // SPRITE_H
