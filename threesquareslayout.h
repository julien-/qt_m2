#ifndef THREESQUARESLAYOUT_H
#define THREESQUARESLAYOUT_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPicture>
#include <QFileDialog>
#include <QImage>
#include <QColor>

#include "ilayout.h"

// class for customization
class ThreeSquaresLayout :public QObject, public QGraphicsItem, public ILayout
{

    Q_OBJECT
public:
    explicit ThreeSquaresLayout(int w, int h);

    QRectF boundingRect() const;

    // overriding paint()
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    int movePointPosX;
    int movePointPosY;

    void setBackgroundColor(QColor color);
    void setCadreStrokeColor(QColor color);
    void setCornerRadius(int radius);
    void setMargin(int margin);

protected:
    int width;
    int height;
    int penWidth;
    int margin;

    QRectF cadres[3];

    QPen  pen;
    QBrush brush;
    QImage image[3];
    QColor backgroundColor;
    QColor strokeColor;


    int radius;
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void updateCadresRect();


signals:

public slots:
    void update_center(QPointF p);
};
#endif // THREESQUARESLAYOUT_H
