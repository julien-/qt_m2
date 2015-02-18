#include "fivecadresscene.h"

FiveCadresScene::FiveCadresScene(int w, int h, QObject *parent):BaseGraphicsScene(w,h)
{
    clear();

    movePointsCount = 4;
    delete movePoint;
    movePoint = new GraphicsEllipseItem*[movePointsCount];
    for(int i=0; i< movePointsCount; i++)
    {
        movePoint[i] = new GraphicsEllipseItem(QRectF(-10, -10, 20,20));
        movePoint[i]->setFlag(QGraphicsItem::ItemIsMovable);
        movePoint[i]->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
        movePoint[i]->setZValue(10);
        addItem(movePoint[i]);
    }

    movePoint[0]->setPos(w/3,h/3);
     movePoint[1]->setPos(w/3*2,h/3);
      movePoint[2]->setPos(w/3,h/3*2);
       movePoint[3]->setPos(w/3*2,h/3*2);

       for(int i=0; i<5; i++){
           GraphicsPolygonItem * polygonItem=new GraphicsPolygonItem();
           addItem(polygonItem);
       }

       mapper = new QSignalMapper(this);
       connect(this->movePoint[0], SIGNAL(ItemMoved(QPointF)), mapper, SLOT(map()));
       connect(this->movePoint[1], SIGNAL(ItemMoved(QPointF)), mapper, SLOT(map()));
       connect(this->movePoint[2], SIGNAL(ItemMoved(QPointF)), mapper, SLOT(map()));
       connect(this->movePoint[3], SIGNAL(ItemMoved(QPointF)), mapper, SLOT(map()));
       mapper->setMapping(this->movePoint[0], 0);
        mapper->setMapping(this->movePoint[1], 1);
         mapper->setMapping(this->movePoint[2], 2);
          mapper->setMapping(this->movePoint[3], 3);
        connect(mapper, SIGNAL(mapped(int)), this, SLOT(onMovePointChange(int)));

       updateCadres();
}

void FiveCadresScene::sceneChanged()
{
    updateCadres();
}

void FiveCadresScene::updateCadres()
{
    int counter =0;
    for(int i=0; i<items().length(); i++){
        QGraphicsItem * qitem =items().at(i);
        if  (qitem->type() == GraphicsPolygonItem::Type )
        {
            GraphicsPolygonItem * item = (GraphicsPolygonItem *)qitem;
            switch (counter) {
            case 0:
                item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( getMargin()*2,0 + getMargin() ) << QPointF( width - getMargin()*2, 0+ getMargin() ) << QPointF( movePoint[1]->x(), movePoint[1]->y() - getMargin() ) << QPointF( movePoint[0]->x(), movePoint[0]->y() - getMargin() )));
                item->update_image();
                counter++;
                break;
            case 1:
                item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( width - getMargin(), 0 + getMargin()*2 ) << QPointF( width - getMargin(), height - getMargin()*2 ) << QPointF( movePoint[3]->x() + getMargin(), movePoint[3]->y()  ) << QPointF( movePoint[1]->x() + getMargin(), movePoint[1]->y() )));
                item->update_image();
                counter++;
                break;
            case 2:
                item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( movePoint[2]->x(), movePoint[2]->y()+getMargin() ) << QPointF( movePoint[3]->x(), movePoint[3]->y()+getMargin() ) << QPointF( width - getMargin()*2, height - getMargin()  ) << QPointF( getMargin()*2, height - getMargin() )));
                counter++;
                item->update_image();
                break;
            case 3:
                item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF(getMargin(), getMargin()*2) << QPointF( movePoint[0]->x() -getMargin(), movePoint[0]->y()  ) << QPointF( movePoint[2]->x()-getMargin(), movePoint[2]->y() ) << QPointF( getMargin(), height - getMargin()*2 )));
                item->update_image();
                counter++;
                break;
            case 4:
                item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( movePoint[0]->x(),movePoint[0]->y() ) << QPointF( movePoint[1]->x(),movePoint[1]->y() ) << QPointF( movePoint[3]->x(),movePoint[3]->y() ) << QPointF( movePoint[2]->x(),movePoint[2]->y() )));
                item->update_image();
                counter++;
                break;
            default:
                break;
            }
        }
    }
}

void FiveCadresScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
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

void FiveCadresScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    for(int i =0; i<4; i++){
         onMovePointChange(i);
    }

    QGraphicsScene::mouseReleaseEvent(event);
    updateCadres();

}

void FiveCadresScene::setMovePoint(QPointF p, int index)
{

}

void FiveCadresScene::changePenStyle(int index)
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == GraphicsPolygonItem::Type )
            ((GraphicsPolygonItem*)item)->setPenStyle(index);
    }
    update();
}

void FiveCadresScene::setCornerRadius(int radius)
{

}

void FiveCadresScene::setCadreStrokeColor(QColor color)
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == GraphicsPolygonItem::Type )
            ((GraphicsPolygonItem*)item)->setCadreStrokeColor(color);
    }
    update();
}

void FiveCadresScene::setCadreStrokeWidth(int val)
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() == GraphicsPolygonItem::Type )
            ((GraphicsPolygonItem*)item)->setCadreStrokeWidth(val);
    }
    update();
}

void FiveCadresScene::onMovePointChange(int index)
{
    if (index == 0)
    {
        movePoint[1]->blockSignals(true);
        movePoint[2]->blockSignals(true);
        movePoint[1]->setY( movePoint[0]->y());
        movePoint[2]->setX( movePoint[0]->x());
        movePoint[1]->blockSignals(false);
        movePoint[2]->blockSignals(false);
    }else if(index == 1){
        movePoint[0]->blockSignals(true);
        movePoint[3]->blockSignals(true);
        movePoint[0]->setY(movePoint[1]->y());
        movePoint[3]->setX(movePoint[1]->x());
        movePoint[0]->blockSignals(false);
        movePoint[3]->blockSignals(false);
    }else if(index == 2){
        movePoint[0]->blockSignals(true);
        movePoint[3]->blockSignals(true);
        movePoint[0]->setX(movePoint[2]->x());
        movePoint[3]->setY(movePoint[2]->y());
        movePoint[0]->blockSignals(false);
        movePoint[3]->blockSignals(false);
    }else if(index == 3){
        movePoint[1]->blockSignals(true);
        movePoint[2]->blockSignals(true);
        movePoint[1]->setX(movePoint[3]->x());
        movePoint[2]->setY(movePoint[3]->y());
        movePoint[1]->blockSignals(false);
        movePoint[2]->blockSignals(false);
    }
    updateCadres();
}
