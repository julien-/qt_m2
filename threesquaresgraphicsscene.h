#ifndef THREESQUARESGRAPHICSSCENE_H
#define THREESQUARESGRAPHICSSCENE_H

#include <QGraphicsSceneMouseEvent>
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>

#include "graphicsellipseitem.h"
#include "graphicsroundedrectangleitem.h"
#include "basegraphicsscene.h"

class ThreeSquaresGraphicsScene: public BaseGraphicsScene
{
    Q_OBJECT
public:
    ThreeSquaresGraphicsScene( int width, int height, QObject *parent = 0);


    void sceneChanged();

private:

    void updateCadresRect();
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
     void setMovePoint(QPointF p, int index=0);
     void changePenStyle(int index);
     void setCornerRadius(int radius);
     void setCadreStrokeColor(QColor color);
     void setCadreStrokeWidth(int val);

};

#endif // THREESQUARESGRAPHICSSCENE_H
