#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mapper = new  QSignalMapper(this);
    connect(ui->radioButton, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->radioButton_2, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->radioButton_3, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->radioButton, 1);
    mapper->setMapping(ui->radioButton_2, 2);
    mapper->setMapping(ui->radioButton_3, 3);
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(onLayoutchanged(int)));

    textDialog = new TextDialog(this);
    connect(textDialog, SIGNAL(onTextAccepted(QString,QFont, QColor)), this, SLOT(addTextItem(QString,QFont, QColor)));

    scene  = new ThreeSquaresGraphicsScene( ui->graphicsView->width(),ui->graphicsView->height(), this);

    ui->graphicsView->setScene(scene);

    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), scene, SLOT(setBlurRadius(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), scene, SLOT(setShadowOffsetX(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), scene, SLOT(setShadowOffsetY(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), scene, SLOT(changePenStyle(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), scene, SLOT(setMargin(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), scene, SLOT(setCornerRadius(int)));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), scene, SLOT(setCadreStrokeWidth(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addTextItem(QString str, QFont font, QColor color){
        QGraphicsTextItem * text = scene->addText(str, font);
        text->setDefaultTextColor(color);
        text->setFlag(QGraphicsItem::ItemIsMovable);
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

void MainWindow::on_pushButton_2_clicked()
{
    textDialog->show();
}

void MainWindow::on_actionSave_triggered()
{
    QImage img = scene->getSceneImage();
    QString path = QFileDialog::getSaveFileName(NULL, tr("Save as image"),"", tr("Images (*.jpg);; Images (*.png)"));
    if (path.isEmpty())
            return;
    img.save(path);

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::onLayoutchanged(int index){
    switch (index) {
    case 1:
        delete scene;
        scene  = new ThreeSquaresGraphicsScene( ui->graphicsView->width(),ui->graphicsView->height(), this);
        ui->graphicsView->setScene(scene);

        break;
    case 2:
        delete scene;
        scene  = new CurvedLinesScene( ui->graphicsView->width(),ui->graphicsView->height(), this);
        ui->graphicsView->setScene(scene);
        break;
    case 3:
        delete scene;
        scene  = new FiveCadresScene(ui->graphicsView->width(),ui->graphicsView->height(), this);
        ui->graphicsView->setScene(scene);
        break;
    default:
        break;
    }

}
