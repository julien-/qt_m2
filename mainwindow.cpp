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
