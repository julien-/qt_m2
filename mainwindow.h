#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QColorDialog>
#include <QGraphicsDropShadowEffect>
#include <QFontDialog>
#include <QSignalMapper>

#include "graphicsellipseitem.h"
#include "graphicsroundedrectangleitem.h"
#include "threesquaresgraphicsscene.h"
#include "curvedlinesscene.h"
#include "textdialog.h"
#include "fivecadresscene.h"

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

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void addTextItem(QString str, QFont font, QColor color);

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void onLayoutchanged(int index);

private:
    Ui::MainWindow *ui;

    BaseGraphicsScene *scene;

    TextDialog  * textDialog;
    QSignalMapper *mapper;



};

#endif // MAINWINDOW_H
