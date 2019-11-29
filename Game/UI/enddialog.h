#ifndef ENDDIALOG_H
#define ENDDIALOG_H

#include <QDialog>

namespace Ui {
class EndDialog;
}

/**
 * @brief This class is for the ending dialog which shows hiscores.
 */
class EndDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the class.
     * @param parent Points to the parent object per Qt's parent-child-system.
     * @param finalScore A map of hiscores.
     */
    explicit EndDialog(QWidget *parent = 0,
                       std::map<std::string,int> finalScore = {});

    /**
     * @brief Parameterless destructor.
     */
    ~EndDialog();

private:
    /**
     * @brief Aligns text for the sake of readibility.
     * @param wordLength
     * @return Alignment marks
     */
    QString aligmentMarks(int wordLength);
    Ui::EndDialog *ui_;
};

#endif // ENDDIALOG_H
