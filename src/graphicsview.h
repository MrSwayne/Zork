#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>
#include "player.h"

class GraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    GraphicsView(QWidget* parent = nullptr, Player *player = nullptr, QGraphicsScene *scene = nullptr);
protected:
private:
    QGraphicsScene *scene;
    Player *player;
public slots:
    void mousePressEvent(QMouseEvent *click);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // GRAPHICSVIEW_H
