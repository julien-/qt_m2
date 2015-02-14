#include "threesquareslayout.h"


ThreeSquaresLayout::ThreeSquaresLayout(int w, int h)
{

    this->penWidth = 5;

    this->width = w-penWidth;
    this->height = h-penWidth;
    this->margin = 10;
    this-> radius= 30;

    this->movePointPosX = w/2;
    this->movePointPosY = h/2;

    backgroundColor = Qt::white;
    strokeColor = Qt::black;

    pen = QPen(strokeColor,penWidth);
    pen.setStyle(Qt::DashLine);

    updateCadresRect();
}

QRectF ThreeSquaresLayout::boundingRect() const
{
    // outer most edges
    return QRectF(0,0, this->width, this->height);
}

void ThreeSquaresLayout::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->setBrush(QBrush(backgroundColor));
   painter->drawRect(0,0,width, height);
   painter->setPen(pen);

   for (int i =0; i<3; i++){
        if  (image[i].isNull() == true)
           painter->setBrush(QBrush());
       else
           painter->setBrush(QBrush(image[i]));

        painter->drawRoundedRect(this->cadres[i],radius,radius);
   }
}

void ThreeSquaresLayout::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (cadres[0].intersects(QRectF(event->pos().x(), event->pos().y(),1,1))){
         //getOpenFileName:  If the user presses Cancel, it returns a null string.
         QString file =  QFileDialog::getOpenFileName(NULL, tr("Open Image"), "/img/", tr("Image Files (*.png *.jpg *.bmp)"));
         if  (file!= NULL){
             image[0] = QImage(file);
         }else{
             image[0] = QImage();
         }
    }else if(cadres[1].intersects(QRectF(event->pos().x(), event->pos().y(),1,1))){
        QString file =  QFileDialog::getOpenFileName(NULL, tr("Open Image"), "/img/", tr("Image Files (*.png *.jpg *.bmp)"));
        if  (file!= NULL){
            image[1] = QImage(file);
        }else{
            image[1] =  QImage();
        }
    }
    else if(cadres[2].intersects(QRectF(event->pos().x(), event->pos().y(),1,1))){
        QString file =  QFileDialog::getOpenFileName(NULL, tr("Open Image"), "/img/", tr("Image Files (*.png *.jpg *.bmp)"));
        if  (file!= NULL){
            image[2] = QImage(file);
        }else{
            image[2] =  QImage();
        }
    }
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
        updateCadresRect();
        update();
}

void ThreeSquaresLayout::updateCadresRect(){
    this->cadres[0] = QRectF(0.0 +margin ,0.0 +margin,movePointPosX - margin*2,movePointPosY-margin*2);
    this->cadres[1] = QRectF(movePointPosX +margin,0.0+margin, this->width - movePointPosX - margin*2, movePointPosY -margin*2);
    this->cadres[2] = QRectF(0.0 + margin, movePointPosY +margin, this->width - margin*2,this->height - movePointPosY - margin*2 );
}

void ThreeSquaresLayout::setBackgroundColor(QColor color){
    backgroundColor = color;
}
void ThreeSquaresLayout::setCadreStrokeColor(QColor color){
    strokeColor = color;
    pen.setColor(color);
}
void ThreeSquaresLayout::setCornerRadius(int r){
    this->radius = r;
     update();
}
void ThreeSquaresLayout::setMargin(int m){
    this->margin = m;
    updateCadresRect();
    update();
}
