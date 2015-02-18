#include "graphicsroundedrectangleitem.h"

GraphicsRoundedRectangleItem::GraphicsRoundedRectangleItem(QRectF rect, int radius):QGraphicsRectItem(rect)
{
    this->drawingCadre = rect;
    this->radius = radius;
    pen = QPen(Qt::black);
    pen.setWidth(3);

    image = QImage();
    originalImage = QImage();
}

void GraphicsRoundedRectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(this->pen);

    if  (image.isNull() == true)
       painter->setBrush(QBrush(Qt::white));
    else
    {
         painter->setBrush(QBrush(image));
    }

     QTransform trans  = QTransform();
     trans.translate(drawingCadre.x(), drawingCadre.y());
     painter->setTransform(trans, true);
     painter->drawRoundedRect(0,0,drawingCadre.width(), drawingCadre.height(), radius,radius);
}

QRectF GraphicsRoundedRectangleItem::boundingRect() const
{
    return QRectF(drawingCadre.x() - pen.width(), drawingCadre.y() - pen.width(), drawingCadre.width()+ pen.width()*2, drawingCadre.height()+ pen.width()*2);
}
void GraphicsRoundedRectangleItem::updateCadre(QRectF rect){
    this->drawingCadre = rect;
    this->setRect(this->drawingCadre);

    if  (originalImage.isNull() == false)
        image = originalImage.scaled(this->drawingCadre.width(), this->drawingCadre.height(), Qt::KeepAspectRatioByExpanding);
    update();
}

void GraphicsRoundedRectangleItem::setRadius(int radius){
    this->radius = radius;
     update();
}

void GraphicsRoundedRectangleItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QString file =  QFileDialog::getOpenFileName(NULL, "Open Image", "/img/", "Image Files (*.png *.jpg *.bmp)");
    if  (file!= NULL){ 
        originalImage = QImage(file);
    }else{
        originalImage = QImage();
    }
    updateCadre(this->getDrawRect());
    update();
}
 QRectF GraphicsRoundedRectangleItem::getDrawRect(){
     return this->drawingCadre;
 }

 int GraphicsRoundedRectangleItem::type() const
 {
     return 8888;
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
