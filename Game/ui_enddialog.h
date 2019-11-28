/********************************************************************************
** Form generated from reading UI file 'enddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDDIALOG_H
#define UI_ENDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EndDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *gameOverLabel;
    QLabel *scoresHeaderLabel;
    QLabel *scoreLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *newGameButton;
    QPushButton *exitButton;

    void setupUi(QDialog *EndDialog)
    {
        if (EndDialog->objectName().isEmpty())
            EndDialog->setObjectName(QStringLiteral("EndDialog"));
        EndDialog->resize(418, 432);
        verticalLayout = new QVBoxLayout(EndDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gameOverLabel = new QLabel(EndDialog);
        gameOverLabel->setObjectName(QStringLiteral("gameOverLabel"));

        verticalLayout->addWidget(gameOverLabel, 0, Qt::AlignHCenter);

        scoresHeaderLabel = new QLabel(EndDialog);
        scoresHeaderLabel->setObjectName(QStringLiteral("scoresHeaderLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scoresHeaderLabel->sizePolicy().hasHeightForWidth());
        scoresHeaderLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(scoresHeaderLabel);

        scoreLabel = new QLabel(EndDialog);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scoreLabel->sizePolicy().hasHeightForWidth());
        scoreLabel->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(scoreLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newGameButton = new QPushButton(EndDialog);
        newGameButton->setObjectName(QStringLiteral("newGameButton"));

        horizontalLayout->addWidget(newGameButton);

        exitButton = new QPushButton(EndDialog);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EndDialog);

        QMetaObject::connectSlotsByName(EndDialog);
    } // setupUi

    void retranslateUi(QDialog *EndDialog)
    {
        EndDialog->setWindowTitle(QApplication::translate("EndDialog", "Dialog", Q_NULLPTR));
        gameOverLabel->setText(QApplication::translate("EndDialog", "Game over!", Q_NULLPTR));
        scoresHeaderLabel->setText(QApplication::translate("EndDialog", "Scores:", Q_NULLPTR));
        scoreLabel->setText(QString());
        newGameButton->setText(QApplication::translate("EndDialog", "New Game", Q_NULLPTR));
        exitButton->setText(QApplication::translate("EndDialog", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EndDialog: public Ui_EndDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDDIALOG_H
