#ifndef THREESQUARESLAYOUT_H
#define THREESQUARESLAYOUT_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

// class for customization
class ThreeSquaresLayout :public QObject, public QGraphicsItem
{

    Q_OBJECT
public:
    explicit ThreeSquaresLayout(int width, int height);

    QRectF boundingRect() const;

    // overriding paint()
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    int movePointPosX;
    int movePointPosY;

protected:
    int width;
    int height;
    int penWidth;
    int margin;



    int radius;
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:

public slots:
    void update_center(QPointF p);
};
#endif // THREESQUARESLAYOUT_H
