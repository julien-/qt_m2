#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene  = new ThreeSquaresGraphicsScene( ui->graphicsView->width(),ui->graphicsView->height(), this);
    ui->graphicsView->setScene(scene);

    movePoint = new GraphicsEllipseItem(QRectF(scene->getMovePointPosX() - 10, scene->getMovePointPosY()  -15, 20,20));
    movePoint->setFlag(QGraphicsItem::ItemIsMovable);
    movePoint->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    scene->addItem(movePoint);

    connect(movePoint, SIGNAL(ItemMoved(QPointF)), scene, SLOT(update_center(QPointF)));
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), scene, SLOT(setBlurRadius(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), scene, SLOT(setShadowOffsetX(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), scene, SLOT(setShadowOffsetY(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), scene, SLOT(changePenStyle(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this);
    if  (ui->radioButton_color_fond->isChecked() && color.isValid() )
        scene->setBackgroundBrush(QBrush(color));
    else if(color.isValid()){
        scene->setCadreStrokeColor(color);
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    scene->setCornerRadius(value);
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    scene->setMargin(value);
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    scene->setCadreStrokeWidth(value);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        ui->spinBox->setEnabled(true);
        ui->spinBox_2->setEnabled(true);
        ui->spinBox_3->setEnabled(true);
        scene->enableShadow();
    }else{
        ui->spinBox->setDisabled(true);
        ui->spinBox_2->setDisabled(true);
        ui->spinBox_3->setDisabled(true);
        scene->disableShadow();
    }
}
