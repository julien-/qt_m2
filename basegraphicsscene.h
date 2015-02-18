#ifndef BASEGRAPHICSSCENE_H
#define BASEGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsDropShadowEffect>
#include <QPainter>

#include "graphicsellipseitem.h"

class BaseGraphicsScene: public QGraphicsScene
{
     Q_OBJECT
public:
    BaseGraphicsScene(int w, int h);

     int MovePointsCount();
     void setMovePointVisible(bool flag, int MovePointindex = 0 );

     QImage getSceneImage();

     void refreshScene();
     virtual void sceneChanged()=0;

     int getMargin();

public slots:
     void setBlurRadius(int blur);
     void setShadowOffsetX(int x);
     void setShadowOffsetY(int y);
     void setMargin(int margin);
     void enableShadow();
     void disableShadow();
     virtual void changePenStyle(int index) =0;
     virtual void setCadreStrokeColor(QColor c) = 0;
     virtual void setCadreStrokeWidth(int val) =0;
     virtual void setCornerRadius(int radius) = 0;

protected:

     GraphicsEllipseItem ** movePoint;
     int width;
     int height;
     int movePointsCount;
     int movePointBoundLimit;

private:

    int margin;
    int penWidth;

    int shadowOffsetX;
    int shadowOffsetY;
    int shadowBlur;

    void updateItemsShadows();
};

#endif // BASEGRAPHICSSCENE_H
