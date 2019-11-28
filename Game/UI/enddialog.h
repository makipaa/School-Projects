#ifndef ENDDIALOG_H
#define ENDDIALOG_H

#include <QDialog>

namespace Ui {
class EndDialog;
}

class EndDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndDialog(QWidget *parent = 0,
                       std::map<std::string,int> finalScore = {});
    ~EndDialog();

private:
    QString aligmentMarks(int wordLength);
    Ui::EndDialog *ui_;
};

#endif // ENDDIALOG_H
