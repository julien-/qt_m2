#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    // create our object and add it to the scene
    layout = new ThreeSquaresLayout(  ui->graphicsView->width(),  ui->graphicsView->height());
    scene-> addItem(layout);

    movePoint = new GraphicsEllipseItem(QRectF(layout->movePointPosX - 10, layout->movePointPosY -10, 20,20));
    movePoint->setFlag(QGraphicsItem::ItemIsMovable);
    movePoint->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    scene->addItem(movePoint);


    connect(movePoint, SIGNAL(ItemMoved(QPointF)), layout, SLOT(update_center(QPointF)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this);
    if  (ui->radioButton_color_fond->isChecked() && color.isValid() )
        layout->setBackgroundColor(color);
    else if(color.isValid()){
        layout->setCadreStrokeColor(color);
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    layout->setCornerRadius(value);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    layout->setMargin(value);
}
