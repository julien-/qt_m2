#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QColorDialog>
#include <QGraphicsDropShadowEffect>

#include "graphicsellipseitem.h"
#include "graphicsroundedrectangleitem.h"
#include "threesquaresgraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    ThreeSquaresGraphicsScene *scene;
    GraphicsEllipseItem * movePoint;

    QGraphicsDropShadowEffect * effect;

};

#endif // MAINWINDOW_H
