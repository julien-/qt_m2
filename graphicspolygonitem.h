#ifndef GRAPHICSPOLYGONITEM_H
#define GRAPHICSPOLYGONITEM_H

#include <QGraphicsPolygonItem>
#include <QFileDialog>
#include <QPainter>

class GraphicsPolygonItem : public QGraphicsPolygonItem
{
    QPen pen;
    QImage image;
    QImage originalImage;
public:
    GraphicsPolygonItem();
    int type() const;
    enum { Type = 999 };
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    void setCadreStrokeColor(QColor color);
    void setCadreStrokeWidth(int val);
    void setPenStyle(int style);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void update_image();
};

#endif // GRAPHICSPOLYGONITEM_H
