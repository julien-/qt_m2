#include "curvedlinesscene.h"

CurvedLinesScene::CurvedLinesScene(int w, int h, QObject *parent): BaseGraphicsScene(w,h)
{
    this->movePoint[0]->setPos(w/2,h/2);

    curvatureSize = w/6;
    movePointBoundLimit = curvatureSize + 100;

    for(int i=0; i<4; i++){
        GraphicsPolygonItem * polygonItem=new GraphicsPolygonItem();
        addItem(polygonItem);
    }

   connect( this->movePoint[0], SIGNAL(ItemMoved(QPointF)), this, SLOT(setMovePoint(QPointF)));

   updateCadres();
}

void CurvedLinesScene::sceneChanged()
{
    updateCadres();
}

void CurvedLinesScene::updateCadres()
{
     int counter =0;
     for(int i=0; i<items().length(); i++){
         QGraphicsItem * qitem =items().at(i);
         if  (qitem->type() == GraphicsPolygonItem::Type )
         {
             GraphicsPolygonItem * item = (GraphicsPolygonItem *)qitem;
             switch (counter) {
             case 0:
                 item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( 0 + getMargin(),0 + getMargin() ) << QPointF( movePoint[0]->x() - getMargin(), 0+ getMargin() ) << QPointF( movePoint[0]->x()- getMargin() + curvatureSize, movePoint[0]->y()/2 ) << QPointF( movePoint[0]->x(),movePoint[0]->y() - getMargin()  ) << QPointF( movePoint[0]->x()/2 + getMargin(), movePoint[0]->y() - curvatureSize - getMargin()) << QPointF( 0 + getMargin(), movePoint[0]->y() - getMargin() )));
                 item->update_image();
                 counter++;
                 break;
             case 1:
                 item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( movePoint[0]->x() + getMargin(),0 + getMargin()) << QPointF( movePoint[0]->x()+getMargin()+curvatureSize, movePoint[0]->y()/2 ) << QPointF( movePoint[0]->x() + getMargin(), movePoint[0]->y()) << QPointF( this->width - (this->width - movePoint[0]->x())/2  + getMargin() ,movePoint[0]->y() - getMargin() + curvatureSize ) << QPointF( this->width - getMargin(), movePoint[0]->y() - getMargin() ) << QPointF( this->width - getMargin(),0 + getMargin() )));
                 item->update_image();
                 counter++;
                 break;
             case 2:
                 counter++;
                 item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( movePoint[0]->x(), movePoint[0]->y() + getMargin()) << QPointF(  this->width - (this->width - movePoint[0]->x())/2  + getMargin(), movePoint[0]->y() + curvatureSize+ getMargin() ) << QPointF( this->width - getMargin(), movePoint[0]->y() + getMargin()) << QPointF( this->width - getMargin(), this->height - getMargin() ) << QPointF( movePoint[0]->x() +getMargin(),this->height - getMargin() ) << QPointF( movePoint[0]->x() - curvatureSize + getMargin(),(this->height - movePoint[0]->y())/2 + movePoint[0]->y() )));
                 item->update_image();
                 break;
             case 3:
                 item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( 0 + getMargin(), movePoint[0]->y() + getMargin()) << QPointF(  movePoint[0]->x()/2 + getMargin(), movePoint[0]->y() - curvatureSize+ getMargin() ) << QPointF( movePoint[0]->x() - getMargin(), movePoint[0]->y()) << QPointF( movePoint[0]->x() - curvatureSize - getMargin(), (this->height - movePoint[0]->y())/2 + movePoint[0]->y() ) << QPointF( movePoint[0]->x() - getMargin(),this->height - getMargin() ) << QPointF( 0 + getMargin(), this->height - getMargin())));
                 item->update_image();
                 counter++;
                 break;
             default:
                 break;
             }
         }
     }
}

void CurvedLinesScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsItem * item = itemAt(mouseEvent->scenePos(), QTransform());

    if(item != NULL && (item->type() == QGraphicsTextItem::Type || item->type() == 4545)){
        QGraphicsScene::mousePressEvent(mouseEvent);

    }
    else if (item != NULL){
        ((GraphicsPolygonItem*)item)->mousePressEvent(mouseEvent);
        updateCadres();
    }
}

void CurvedLinesScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(movePoint[0]->x() >width - movePointBoundLimit){
        movePoint[0]->setPos(width - movePointBoundLimit ,movePoint[0]->y());
        mouseReleaseEvent(event);
    }
    else if(movePoint[0]->x() < movePointBoundLimit){
         movePoint[0]->setPos(movePointBoundLimit, movePoint[0]->y());
          mouseReleaseEvent(event);
    }
    else if( movePoint[0]->y() < movePointBoundLimit){
        movePoint[0]->setPos(movePoint[0]->x(),movePointBoundLimit);
         mouseReleaseEvent(event);
        }
    else if( movePoint[0]->y() > height - movePointBoundLimit ){
        movePoint[0]->setPos(movePoint[0]->x(), height - movePointBoundLimit );
         mouseReleaseEvent(event);
        }
    QGraphicsScene::mouseReleaseEvent(event);
    updateCadres();
}

void CurvedLinesScene::setMovePoint(QPointF p, int index)
{
    if (movePoint[0]->x() < width - movePointBoundLimit && movePoint[0]->x() > movePointBoundLimit && movePoint[0]->y() > movePointBoundLimit && movePoint[0]->y() < height - movePointBoundLimit )
        updateCadres();
    else{
        movePoint[0]->blockSignals(true);
        if(movePoint[0]->x() >width - movePointBoundLimit){
            movePoint[0]->setPos(width - movePointBoundLimit ,movePoint[0]->y());
            setMovePoint(p, index);
        }
        else if(movePoint[0]->x() < movePointBoundLimit){
             movePoint[0]->setPos(movePointBoundLimit, movePoint[0]->y());
              setMovePoint(p, index);
        }
        else if( movePoint[0]->y() < movePointBoundLimit){
            movePoint[0]->setPos(movePoint[0]->x(),movePointBoundLimit);
             setMovePoint(p, index);
            }
        else if( movePoint[0]->y() > height - movePointBoundLimit ){
            movePoint[0]->setPos(movePoint[0]->x(), height - movePointBoundLimit );
              setMovePoint(p, index);
            }
        movePoint[0]->blockSignals(false);
        updateCadres();
    }
}

void CurvedLinesScene::changePenStyle(int index)
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == GraphicsPolygonItem::Type )
            ((GraphicsPolygonItem*)item)->setPenStyle(index);
    }
    update();
}

void CurvedLinesScene::setCornerRadius(int radius)
{
        //empty
}

void CurvedLinesScene::setCadreStrokeColor(QColor color)
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == GraphicsPolygonItem::Type )
            ((GraphicsPolygonItem*)item)->setCadreStrokeColor(color);
    }
    update();
}

void CurvedLinesScene::setCadreStrokeWidth(int val)
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == GraphicsPolygonItem::Type )
            ((GraphicsPolygonItem*)item)->setCadreStrokeWidth(val);
    }
    update();
}
