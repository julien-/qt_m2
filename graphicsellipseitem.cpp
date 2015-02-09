#include "graphicsellipseitem.h"

GraphicsEllipseItem::GraphicsEllipseItem(QRectF rect) :
    QGraphicsEllipseItem(rect)
{

}

QVariant GraphicsEllipseItem::itemChange( GraphicsItemChange change, const QVariant  &value )
{
  if (change == ItemPositionChange){
    emit ItemMoved(value.toPointF());
  }
  return QGraphicsEllipseItem::itemChange(change, value);
}
