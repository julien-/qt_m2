#include "threesquaresgraphicsscene.h"

ThreeSquaresGraphicsScene::ThreeSquaresGraphicsScene(int width, int height, QObject *parent): QGraphicsScene(parent)
{
    this->penWidth = 5;
    this->margin = 10;

    this->width = width - margin;
    this->height = height - margin;

    this->movePointPosX =  this->width/2;
    this->movePointPosY =  this->height/2;

    this->shadowOffsetX =1;
    this->shadowOffsetY =1;
    this->shadowBlur = 10;

    setSceneRect(0,0,this->width, this->height);

    addItem(new GraphicsRoundedRectangleItem(QRectF(), 30));
    addItem(new GraphicsRoundedRectangleItem(QRectF(), 30));
    addItem(new GraphicsRoundedRectangleItem(QRectF(), 30));

    updateCadresRect();

}

void ThreeSquaresGraphicsScene::updateCadresRect(){
    ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(0))->updateCadre(QRectF(0.0 +margin ,0.0 +margin,movePointPosX - margin*2,movePointPosY-margin*2));
    ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(1))->updateCadre(QRectF(movePointPosX +margin,0.0+margin, this->width - movePointPosX - margin*2, movePointPosY -margin*2));
    ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(2))->updateCadre(QRectF(0.0 + margin, movePointPosY +margin, this->width - margin*2,this->height - movePointPosY - margin*2 ));

}
int ThreeSquaresGraphicsScene::getMovePointPosX(){
    return this->movePointPosX;
}
int ThreeSquaresGraphicsScene::getMovePointPosY(){
    return this->movePointPosY;
}
void ThreeSquaresGraphicsScene::update_center(QPointF p){
        movePointPosX = width/2 +  p.x();
        movePointPosY = height/2 + p.y();
        printf("movePointPosX %i\n", movePointPosX);
        updateCadresRect();
        invalidate();
        update_childrens();
}

void ThreeSquaresGraphicsScene::update_childrens(){
    for(int i=0; i<3; i++){
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->update();
    }
}

void ThreeSquaresGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    for(int i=0; i<3; i++){
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        if (item->getDrawRect().intersects(QRectF(event->scenePos().x(), event->scenePos().y(),1,1))){
            item->mousePressEvent(event);
        }
    }


     QGraphicsScene::mousePressEvent(event);
}
void ThreeSquaresGraphicsScene::setCornerRadius(int r){
    for(int i=0; i<3; i++){
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setRadius(r);
    }
    update();
}
void ThreeSquaresGraphicsScene::setMargin(int m){
    this->margin = m;
    updateCadresRect();
    update();
}
void ThreeSquaresGraphicsScene::setCadreStrokeColor(QColor color){
    for(int i=0; i<3; i++){
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setCadreStrokeColor(color);
    }
}
void ThreeSquaresGraphicsScene::setCadreStrokeWidth(int val){
    for(int i=0; i<3; i++){
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setCadreStrokeWidth(val);
    }
    update();
}
void ThreeSquaresGraphicsScene::enableShadow(){
    for(int i=0; i<3; i++){
        QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect();
        effect->setOffset(this->shadowOffsetX,this->shadowOffsetY);
        effect->setBlurRadius(this->shadowBlur);
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setGraphicsEffect(effect);
        item->blockSignals(false);
    }
    update();
}
void ThreeSquaresGraphicsScene::disableShadow(){
    for(int i=0; i<3; i++){
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->graphicsEffect()->setEnabled(false);
    }
    update();
}
void ThreeSquaresGraphicsScene::setBlurRadius(int blur){
    this->shadowBlur = blur;
    for(int i=0; i<3; i++){
        QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect();
        effect->setOffset(this->shadowOffsetX,this->shadowOffsetY);
        effect->setBlurRadius(this->shadowBlur);
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setGraphicsEffect(effect);
    }
    update();
}
void ThreeSquaresGraphicsScene::setShadowOffsetX(int x){
    this->shadowOffsetX = x;
    for(int i=0; i<3; i++){
        QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect();
        effect->setOffset(x,this->shadowOffsetY);
        effect->setBlurRadius(this->shadowBlur);
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setGraphicsEffect(effect);
    }
    update();
}
void ThreeSquaresGraphicsScene::setShadowOffsetY(int y){
    this->shadowOffsetY = y;
    for(int i=0; i<3; i++){
        QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect();
        effect->setOffset(y,this->shadowOffsetY);
        effect->setBlurRadius(this->shadowBlur);
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setGraphicsEffect(effect);
    }
}
void  ThreeSquaresGraphicsScene::changePenStyle(int index){
    for(int i=0; i<3; i++){
        GraphicsRoundedRectangleItem * item = ((GraphicsRoundedRectangleItem*)this->items(Qt::AscendingOrder).at(i));
        item->setPenStyle(index);
    }
     update();
}
