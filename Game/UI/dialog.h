#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "mainwindow.hh"
#include "core/player.h"


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
    void sendPlayer(std::vector<std::shared_ptr<Student::Player>> players);

    void sendMapValue(int size);

    void sendRoundValue(int size);

private:
    void updateColorOptions();

    void addPlayer();

    void showMessage(QString message);

    Ui::Dialog *ui_;
    std::vector<std::shared_ptr<Student::Player>> players_;
    std::vector<QColor> colorOptions_;

};

#endif // DIALOG_H
