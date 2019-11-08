#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mapwindow.hh"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
   virtual void accept();
   virtual void showValue();

signals:
    void sendValue(int heigth);

private:
    Ui::Dialog *ui;
};


#endif // DIALOG_H
