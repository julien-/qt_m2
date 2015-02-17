#include "textdialog.h"
#include "ui_textdialog.h"

TextDialog::TextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextDialog)
{
    ui->setupUi(this);
    color = QColor(Qt::black);
    font = QFont();
}

TextDialog::~TextDialog()
{
    delete ui;
}

void TextDialog::on_pushButton_clicked()
{
    bool ok;
    font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
}

void TextDialog::on_buttonBox_accepted()
{
    if(ui->lineEdit->text().size()>0)
    emit onTextAccepted(ui->lineEdit->text(), font, this->color);
}

void TextDialog::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this);
    if  (color.isValid())
       this->color = color;
}
