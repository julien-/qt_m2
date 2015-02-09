#ifndef GRAPHICSELLIPSEITEM_H
#define GRAPHICSELLIPSEITEM_H

#include <QObject>
#include <QGraphicsEllipseItem>

class GraphicsEllipseItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit GraphicsEllipseItem( QRectF rect);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

signals:
     void ItemMoved(QPointF p);

};

#endif // GRAPHICSELLIPSEITEM_H
