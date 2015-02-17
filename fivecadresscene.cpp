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
       updateCadres();
}

void FiveCadresScene::sceneChanged()
{

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
                item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( 0 + getMargin(),0 + getMargin() ) << QPointF( width - getMargin(), 0+ getMargin() ) << QPointF( movePoint[1]->x(), movePoint[1]->y() - getMargin() ) << QPointF( movePoint[0]->x(), movePoint[0]->y() - getMargin() )));
                item->update_image();
                counter++;
                break;
            case 1:
                item->setPolygon( QPolygonF( QVector<QPointF>() << QPointF( width - getMargin(), 0 + getMargin() ) << QPointF( width - getMargin(), height - getMargin() ) << QPointF( movePoint[3]->x() + getMargin(), movePoint[3]->y()  ) << QPointF( movePoint[1]->x() + getMargin(), movePoint[1]->y() )));
                item->update_image();
                counter++;
                break;
            case 2:
                counter++;
                item->update_image();
                break;
            case 3:
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
      QGraphicsScene::mousePressEvent(mouseEvent);
}

void FiveCadresScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

void FiveCadresScene::setMovePoint(QPointF p, int index)
{

}

void FiveCadresScene::changePenStyle(int index)
{

}

void FiveCadresScene::setCornerRadius(int radius)
{

}

void FiveCadresScene::setCadreStrokeColor(QColor color)
{

}

void FiveCadresScene::setCadreStrokeWidth(int val)
{

}
