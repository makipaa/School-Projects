#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "mainwindow.hh"
#include "core/player.h"


namespace Ui {
class Dialog;
}

/**
 * @brief This class is for the starting dialog in the game. \n
 * It needs map size, rounds and players as input.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the dialog.
     * @param parent Points to the parent object per Qt's parent-child-system.
     */
    explicit Dialog(QWidget *parent = 0);

    /**
     * @brief Paramerless destructor.
     */
    ~Dialog();

public slots:
    /**
     * @brief Shows slider value in the lcd-screens.
     */
    virtual void showValue();

signals:
    /**
     * @brief Sends players to the MainWindow.
     * @param players
     */
    void sendPlayer(std::vector<std::shared_ptr<Student::Player>> players);

    /**
     * @brief Sends map size to the MainWindow.
     * @param size
     */
    void sendMapValue(int size);

    /**
     * @brief Sends round numbers to the MainWindow.
     * @param round
     */
    void sendRoundValue(int round);

private:
    /**
     * @brief Emits signals as the accept button is pressed.
     */
    virtual void accept();

    /**
     * @brief Keeps track of player colors.
     */
    void updateColorOptions();

    /**
     * @brief Adds players to the game if their names are suitable.
     * @post Exception Guarantee: Basic.
     */
    void addPlayer();

    /**
     * @brief Shows a informative message in the dialog.
     * @param message
     */
    void showMessage(QString message);

    Ui::Dialog *ui_;
    std::vector<std::shared_ptr<Student::Player>> players_;
    std::vector<QColor> colorOptions_;

};

#endif // DIALOG_H
