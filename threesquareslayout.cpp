#include "threesquareslayout.h"


ThreeSquaresLayout::ThreeSquaresLayout(int width, int height)
{
   this->penWidth = 5;
   this->width = width-penWidth;
   this->height = height-penWidth;
   this->margin = 15;
    this-> radius= 60;

    this->movePointPosX = width/2;
    this->movePointPosY = height/2;
}

QRectF ThreeSquaresLayout::boundingRect() const
{
    // outer most edges
    return QRectF(0,0, this->width, this->height);
}

void ThreeSquaresLayout::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   QRectF rect = boundingRect();

   QPen pen(Qt::black,penWidth);
   pen.setStyle(Qt::DashLine);

  // this->setFlag(GraphicsItemFlag::ItemIsMovable);
   painter->setPen(pen);
  // painter->drawEllipse(QRectF(width/2 - 10, height/2 -10, 20,20 ));
   // painter->drawRect(QRectF(0.0,0.0,this->width,this->height));
   painter->drawRoundedRect(QRectF(0.0 +margin ,0.0 +margin,movePointPosX - margin*2,movePointPosY-margin*2),radius,radius);
   painter->drawRoundedRect(QRectF(movePointPosX +margin,0.0+margin, width - movePointPosX - margin*2, movePointPosY -margin*2),radius,radius);
   painter->drawRoundedRect(QRectF(0.0 + margin, movePointPosY +margin, width - margin*2,height - movePointPosY - margin*2 ),radius,radius);
}

void ThreeSquaresLayout::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void ThreeSquaresLayout::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
void ThreeSquaresLayout::update_center(QPointF p){
        movePointPosX = width/2 +  p.x();
        movePointPosY = height/2 + p.y();
        update();
}
