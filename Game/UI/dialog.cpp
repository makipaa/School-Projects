#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->acceptButton, &QPushButton::clicked, this, &Dialog::accept);
    connect(ui->mapSizeSlider, &QSlider::valueChanged, this, &Dialog::showValue);

    ui->lcdMapSize->display(ui->mapSizeSlider->value());
    ui->mapSizeSlider->setMaximum(50);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::accept(){

    int value = ui->mapSizeSlider->value();
    emit sendValue(value);
    QDialog::accept();
}

void Dialog::showValue(){
    int value = ui->mapSizeSlider->value();
    ui->lcdMapSize->display(value);
}
