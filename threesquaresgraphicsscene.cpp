#include "threesquaresgraphicsscene.h"

ThreeSquaresGraphicsScene::ThreeSquaresGraphicsScene(int w, int h, QObject *parent): BaseGraphicsScene(w, h)
{
    this->movePoint[0]->setPos(w/2,h/2);

    addItem(new GraphicsRoundedRectangleItem(QRectF(), 30));
    addItem(new GraphicsRoundedRectangleItem(QRectF(), 30));
    addItem(new GraphicsRoundedRectangleItem(QRectF(), 30));

    connect( this->movePoint[0], SIGNAL(ItemMoved(QPointF)), this, SLOT(setMovePoint(QPointF)));

    updateCadresRect();
}

void ThreeSquaresGraphicsScene::updateCadresRect(){
    int counter =0;
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == 8888 )
        {
            switch (counter) {
            case 0:
                ((GraphicsRoundedRectangleItem*)item)->updateCadre(QRectF(0.0 +this->getMargin() ,0.0 +this->getMargin(),this->movePoint[0]->x() - this->getMargin()*2,this->movePoint[0]->y()-this->getMargin()*2));
                counter++;
                break;
            case 1:
                ((GraphicsRoundedRectangleItem*)item)->updateCadre(QRectF(this->movePoint[0]->x() + this->getMargin(),0.0+this->getMargin(), this->width - this->movePoint[0]->x() - getMargin()*2, this->movePoint[0]->y() -getMargin()*2));
                counter++;
                break;
            case 2:
                ((GraphicsRoundedRectangleItem*)item)->updateCadre(QRectF(0.0 + getMargin(), this->movePoint[0]->y() +getMargin(), this->width - getMargin()*2,this->height - this->movePoint[0]->y() - getMargin()*2 ));
                 counter++;
                break;
            default:
                break;
            }
             }
    }
    update();
}

void ThreeSquaresGraphicsScene::setMovePoint(QPointF p, int index){
        updateCadresRect();
}

void ThreeSquaresGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem * item = itemAt(event->scenePos(), QTransform());

    if(item != NULL && (item->type() == QGraphicsTextItem::Type || item->type() == 4545)){
        QGraphicsScene::mousePressEvent(event);
    }
    else{
        for(int i=0; i<3; i++){
            GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
            if (item->getDrawRect().intersects(QRectF(event->scenePos().x(), event->scenePos().y(),1,1))){
                item->mousePressEvent(event);
            }
        }
         QGraphicsScene::mousePressEvent(event);
    }
}

void ThreeSquaresGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    updateCadresRect();
}
void ThreeSquaresGraphicsScene::setCornerRadius(int r){

    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == 8888 )
            ((GraphicsRoundedRectangleItem*)item)->setRadius(r);
    }
    update();
}

void ThreeSquaresGraphicsScene::setCadreStrokeColor(QColor color){
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == 8888 )
            ((GraphicsRoundedRectangleItem*)item)->setCadreStrokeColor(color);
    }
    update();
}
void ThreeSquaresGraphicsScene::setCadreStrokeWidth(int val){
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == 8888 )
            ((GraphicsRoundedRectangleItem*)item)->setCadreStrokeWidth(val);
    }
    update();
}

void ThreeSquaresGraphicsScene::sceneChanged()
{
    updateCadresRect();
}
void  ThreeSquaresGraphicsScene::changePenStyle(int index){
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == 8888 )
            ((GraphicsRoundedRectangleItem*)item)->setPenStyle(index);
    }
    update();
}
