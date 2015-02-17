#include "graphicsellipseitem.h"

GraphicsEllipseItem::GraphicsEllipseItem(QRectF rect) :
    QGraphicsEllipseItem(rect)
{

}
QRectF GraphicsEllipseItem::boundingRect() const{
    return this->rect();
}

QVariant GraphicsEllipseItem::itemChange( GraphicsItemChange change, const QVariant  &value )
{
  if (change == ItemPositionChange){
    emit ItemMoved(value.toPointF());
  }
  return QGraphicsEllipseItem::itemChange(change, value);
}
int GraphicsEllipseItem::type() const{
    return 4545;
}
