#ifndef TEXTDIALOG_H
#define TEXTDIALOG_H

#include <QDialog>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>

namespace Ui {
class TextDialog;
}

class TextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TextDialog(QWidget *parent = 0);
    ~TextDialog();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_pushButton_2_clicked();

private:
    Ui::TextDialog *ui;

    QFont font;
    QColor color;
signals:
    void onTextAccepted(QString text, QFont font, QColor color);

};

#endif // TEXTDIALOG_H
