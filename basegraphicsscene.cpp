#include "basegraphicsscene.h"

BaseGraphicsScene::BaseGraphicsScene(int w, int h): QGraphicsScene(0,0,w,h)
{
    this->width = w -2;
    this->height =h -2;
    this->setSceneRect(0,0,w-2,h-2);

    movePointsCount = 1;
    movePoint = new GraphicsEllipseItem*[movePointsCount];
    movePoint[0] = new GraphicsEllipseItem(QRectF(-10, -10, 20,20));
    movePoint[0]->setFlag(QGraphicsItem::ItemIsMovable);
    movePoint[0]->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    movePoint[0]->setZValue(10);
    addItem(movePoint[0]);

    margin =10;
    this->shadowOffsetX =1;
    this->shadowOffsetY =1;
    this->shadowBlur = 1;
}

int BaseGraphicsScene::MovePointsCount()
{
    return movePointsCount;
}

void BaseGraphicsScene::setMovePointVisible(bool flag, int MovePointindex)
{
    if(MovePointindex >=0 && MovePointindex < movePointsCount){
        movePoint[MovePointindex]->setEnabled(flag);
    }
}


void BaseGraphicsScene::setMargin(int margin)
{
    this->margin = margin;
    sceneChanged();
}

void BaseGraphicsScene::setBlurRadius(int radius)
{
    this->shadowBlur = radius;
    updateItemsShadows();
}

void BaseGraphicsScene::setShadowOffsetX(int x)
{
    this->shadowOffsetX =x;
    updateItemsShadows();
}

void BaseGraphicsScene::setShadowOffsetY(int y)
{
    this->shadowOffsetY =y;
    updateItemsShadows();
}

void BaseGraphicsScene::enableShadow()
{
   updateItemsShadows();
}

void BaseGraphicsScene::disableShadow()
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() != 4545 && item->graphicsEffect() &&  item->graphicsEffect()->isEnabled())
        {
           item->graphicsEffect()->setEnabled(false);
        }
    }
    update();
}

QImage BaseGraphicsScene::getSceneImage()
{
    setMovePointVisible(false);

    QImage pixmap(QSize(this->width, this->height), QImage::Format_ARGB32);
    pixmap.fill(Qt::white);

    QPainter imagePainter(&pixmap);
    imagePainter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

    this->render(&imagePainter);

    setMovePointVisible(true);

    return pixmap;
}

void BaseGraphicsScene::refreshScene()
{
   for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        item->update();
   }
}

int BaseGraphicsScene::getMargin()
{
    return margin;
}

void BaseGraphicsScene::updateItemsShadows()
{
    for(int i=0; i<items().length(); i++){
        QGraphicsItem *item =items().at(i);
        if  (item->type() != 4545)
        {
              QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect();
              effect->setOffset(this->shadowOffsetX,this->shadowOffsetY);
              effect->setBlurRadius(this->shadowBlur);
              item->setGraphicsEffect(effect);
        }
    }
    update();
}

