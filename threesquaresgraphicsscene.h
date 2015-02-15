#ifndef THREESQUARESGRAPHICSSCENE_H
#define THREESQUARESGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>

#include "graphicsroundedrectangleitem.h"

class ThreeSquaresGraphicsScene: public QGraphicsScene
{
    Q_OBJECT
public:
    ThreeSquaresGraphicsScene( int width, int height, QObject *parent = 0);
    int getMovePointPosX();
    int getMovePointPosY();


    void setCornerRadius(int radius);
    void setMargin(int margin);
    void setCadreStrokeColor(QColor color);
    void setCadreStrokeWidth(int val);


private:

    int movePointPosX;
    int movePointPosY;
    int margin;
    int penWidth;

    int width;
    int height;

    int shadowOffsetX;
    int shadowOffsetY;
    int shadowBlur;

    void updateCadresRect();
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
public slots:
     void update_center(QPointF p);
     void update_childrens();
     void setBlurRadius(int blur);
     void setShadowOffsetX(int x);
     void setShadowOffsetY(int y);
     void changePenStyle(int index);
     void enableShadow();
     void disableShadow();
};

#endif // THREESQUARESGRAPHICSSCENE_H
