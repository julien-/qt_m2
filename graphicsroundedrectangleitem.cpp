#include "graphicsroundedrectangleitem.h"

GraphicsRoundedRectangleItem::GraphicsRoundedRectangleItem(QRectF rect, int radius)
{
    this->drawingCadre = rect;
    this->radius = radius;
    pen = QPen(Qt::black);
    pen.setWidth(3);
}

void GraphicsRoundedRectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(this->pen);

    if  (image.isNull() == true)
       painter->setBrush(QBrush(Qt::white));
   else
       painter->setBrush(QBrush(image));
    painter->drawRoundedRect(this->drawingCadre,radius,radius);

}

QRectF GraphicsRoundedRectangleItem::boundingRect() const
{
    return this->drawingCadre;
}
void GraphicsRoundedRectangleItem::updateCadre(QRectF rect){
    this->drawingCadre = rect;
     update();
}

void GraphicsRoundedRectangleItem::setRadius(int radius){
    this->radius = radius;
     update();
}

void GraphicsRoundedRectangleItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QString file =  QFileDialog::getOpenFileName(NULL, "Open Image", "/img/", "Image Files (*.png *.jpg *.bmp)");
    if  (file!= NULL){
        image = QImage(file);
    }else{
        image = QImage();
    }
     update();
}
 QRectF GraphicsRoundedRectangleItem::getDrawRect(){
     return this->drawingCadre;
 }
 void GraphicsRoundedRectangleItem::setCadreStrokeColor(QColor color){
     pen.setColor(color);
      update();
 }
 void GraphicsRoundedRectangleItem::setCadreStrokeWidth(int val){
     pen.setWidth(val);
      update();
 }
 void GraphicsRoundedRectangleItem::setPenStyle(int style){
     switch (style) {
     case 0:
         pen.setStyle(Qt::SolidLine);
         break;
     case 1:
         pen.setStyle(Qt::DashLine);
         break;
     case 2:
         pen.setStyle(Qt::DotLine);
         break;
     case 3:
         pen.setStyle(Qt::DashDotLine);
         break;
     case 4:
         pen.setStyle(Qt::DashDotDotLine);
         break;

     default:
         break;
     }
     update();

 }
