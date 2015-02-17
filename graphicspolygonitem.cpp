#include "graphicspolygonitem.h"

GraphicsPolygonItem::GraphicsPolygonItem()
{
    pen = QPen(Qt::black);
    pen.setWidth(3);

    image = QImage();
    originalImage = QImage();
}

int GraphicsPolygonItem::type() const
{
    return Type;
}

void GraphicsPolygonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(this->pen);

    if  (image.isNull() == true)
       painter->setBrush(QBrush(Qt::white));
    else
    {
         painter->setBrush(QBrush(image));
    }
    painter->drawPolygon(this->polygon());
}

void GraphicsPolygonItem::setCadreStrokeColor(QColor color)
{
    pen.setColor(color);
     update();
}

void GraphicsPolygonItem::setCadreStrokeWidth(int val)
{
    this->pen.setWidth(val);
    update();
}

void GraphicsPolygonItem::setPenStyle(int style)
{
    switch (style) {
    case 0:
        pen.setStyle(Qt::SolidLine);
        break;
    case 1:
        pen.setStyle(Qt::DashLine);
        break;
    case 2:
        pen.setStyle(Qt::DotLine);
        break;
    case 3:
        pen.setStyle(Qt::DashDotLine);
        break;
    case 4:
        pen.setStyle(Qt::DashDotDotLine);
        break;

    default:
        break;
    }
    update();
}

void GraphicsPolygonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QString file =  QFileDialog::getOpenFileName(NULL, "Open Image", "/img/", "Image Files (*.png *.jpg *.bmp)");
    if  (file!= NULL){
        originalImage = QImage(file);
    }else{
        originalImage = QImage();
    }
    update();
}

void GraphicsPolygonItem::update_image()
{
    if  (originalImage.isNull() == false)
        image = originalImage.scaled(this->boundingRect().width(), this->boundingRect().height(), Qt::KeepAspectRatioByExpanding);
}



