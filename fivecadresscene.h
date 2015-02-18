#ifndef FIVECADRESSCENE_H
#define FIVECADRESSCENE_H

#include <QSignalMapper>
#include <QGraphicsSceneMouseEvent>

#include "basegraphicsscene.h"
#include "graphicspolygonitem.h"


class FiveCadresScene : public BaseGraphicsScene
{
    Q_OBJECT
public:
    FiveCadresScene(int w, int h, QObject *parent = 0);

    void sceneChanged();

private:
    QSignalMapper * mapper;
    void updateCadres();
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
     void setMovePoint(QPointF p, int index=0);
     void changePenStyle(int index);
     void setCornerRadius(int radius);
     void setCadreStrokeColor(QColor color);
     void setCadreStrokeWidth(int val);
     void onMovePointChange(int index);
};

#endif // FIVECADRESSCENE_H
