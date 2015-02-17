#ifndef CURVEDLINESSCENE_H
#define CURVEDLINESSCENE_H

#include <QGraphicsSceneMouseEvent>

#include "graphicsellipseitem.h"
#include "basegraphicsscene.h"
#include "graphicspolygonitem.h"

class CurvedLinesScene: public BaseGraphicsScene
{
    Q_OBJECT
public:
    CurvedLinesScene(int w, int h, QObject *parent = 0);

    void sceneChanged();

private:
    int curvatureSize;
    void updateCadres();
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
     void setMovePoint(QPointF p, int index=0);
     void changePenStyle(int index);
     void setCornerRadius(int radius);
     void setCadreStrokeColor(QColor color);
     void setCadreStrokeWidth(int val);
};

#endif // CURVEDLINESSCENE_H
