#ifndef GRAPHICSROUNDEDRECTANGLEITEM_H
#define GRAPHICSROUNDEDRECTANGLEITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QFileDialog>
#include <QObject>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsEffect>

class GraphicsRoundedRectangleItem: public QObject, public QGraphicsRectItem
{
     Q_OBJECT
public:
    explicit  GraphicsRoundedRectangleItem(QRectF rect, int radius);
    QRectF boundingRect() const;
    void paint(QPainter * painter,const QStyleOptionGraphicsItem * option, QWidget * widget);
    void updateCadre(QRectF rect);
    void setRadius(int radius);
    void setCadreStrokeColor(QColor color);
    void setCadreStrokeWidth(int val);
    void setPenStyle(int style);
    QRectF getDrawRect();
    int type() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QRectF drawingCadre;
    QImage originalImage;
    QImage image;
    int radius;
    QPen pen;

protected:

signals:

public slots:

};

#endif // GRAPHICSROUNDEDRECTANGLEITEM_H
