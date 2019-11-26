/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLCDNumber *lcdRounds;
    QLabel *headingLabel;
    QLabel *roundLabel;
    QLCDNumber *lcdMapSize;
    QSlider *mapSizeSlider;
    QSlider *roundSlider;
    QLabel *mapLabel;
    QLabel *pic1Label;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *nameLabel;
    QLineEdit *nameInput;
    QLabel *showPlayersLabel;
    QLabel *infoLabel;
    QPushButton *acceptButton;
    QPushButton *addPlayersButton;
    QComboBox *comboBox;
    QLabel *color_label;
    QLabel *addplayers_label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(418, 432);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 401, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lcdRounds = new QLCDNumber(gridLayoutWidget);
        lcdRounds->setObjectName(QStringLiteral("lcdRounds"));

        gridLayout->addWidget(lcdRounds, 4, 3, 1, 2);

        headingLabel = new QLabel(gridLayoutWidget);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));

        gridLayout->addWidget(headingLabel, 3, 0, 1, 1);

        roundLabel = new QLabel(gridLayoutWidget);
        roundLabel->setObjectName(QStringLiteral("roundLabel"));

        gridLayout->addWidget(roundLabel, 4, 0, 1, 1);

        lcdMapSize = new QLCDNumber(gridLayoutWidget);
        lcdMapSize->setObjectName(QStringLiteral("lcdMapSize"));

        gridLayout->addWidget(lcdMapSize, 3, 3, 1, 2);

        mapSizeSlider = new QSlider(gridLayoutWidget);
        mapSizeSlider->setObjectName(QStringLiteral("mapSizeSlider"));
        mapSizeSlider->setMinimum(10);
        mapSizeSlider->setMaximum(100);
        mapSizeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(mapSizeSlider, 3, 1, 1, 2);

        roundSlider = new QSlider(gridLayoutWidget);
        roundSlider->setObjectName(QStringLiteral("roundSlider"));
        roundSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(roundSlider, 4, 1, 1, 2);

        mapLabel = new QLabel(gridLayoutWidget);
        mapLabel->setObjectName(QStringLiteral("mapLabel"));

        gridLayout->addWidget(mapLabel, 0, 0, 1, 2);

        pic1Label = new QLabel(gridLayoutWidget);
        pic1Label->setObjectName(QStringLiteral("pic1Label"));
        pic1Label->setEnabled(true);

        gridLayout->addWidget(pic1Label, 0, 3, 1, 2);

        gridLayoutWidget_2 = new QWidget(Dialog);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 180, 401, 251));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(gridLayoutWidget_2);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout_2->addWidget(nameLabel, 1, 0, 1, 1);

        nameInput = new QLineEdit(gridLayoutWidget_2);
        nameInput->setObjectName(QStringLiteral("nameInput"));

        gridLayout_2->addWidget(nameInput, 3, 0, 1, 1);

        showPlayersLabel = new QLabel(gridLayoutWidget_2);
        showPlayersLabel->setObjectName(QStringLiteral("showPlayersLabel"));

        gridLayout_2->addWidget(showPlayersLabel, 4, 0, 3, 1);

        infoLabel = new QLabel(gridLayoutWidget_2);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));

        gridLayout_2->addWidget(infoLabel, 7, 0, 1, 1);

        acceptButton = new QPushButton(gridLayoutWidget_2);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));

        gridLayout_2->addWidget(acceptButton, 7, 1, 1, 1);

        addPlayersButton = new QPushButton(gridLayoutWidget_2);
        addPlayersButton->setObjectName(QStringLiteral("addPlayersButton"));

        gridLayout_2->addWidget(addPlayersButton, 4, 1, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 3, 1, 1, 1);

        color_label = new QLabel(gridLayoutWidget_2);
        color_label->setObjectName(QStringLiteral("color_label"));

        gridLayout_2->addWidget(color_label, 1, 1, 1, 1);

        addplayers_label = new QLabel(gridLayoutWidget_2);
        addplayers_label->setObjectName(QStringLiteral("addplayers_label"));

        gridLayout_2->addWidget(addplayers_label, 0, 0, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        headingLabel->setText(QApplication::translate("Dialog", "Set map size", Q_NULLPTR));
        roundLabel->setText(QApplication::translate("Dialog", "Set rounds", Q_NULLPTR));
        mapLabel->setText(QApplication::translate("Dialog", "Game Settings", Q_NULLPTR));
        pic1Label->setText(QString());
        nameLabel->setText(QApplication::translate("Dialog", "Name", Q_NULLPTR));
        showPlayersLabel->setText(QString());
        infoLabel->setText(QString());
        acceptButton->setText(QApplication::translate("Dialog", "Accept", Q_NULLPTR));
        addPlayersButton->setText(QApplication::translate("Dialog", "Add", Q_NULLPTR));
        color_label->setText(QApplication::translate("Dialog", "Color", Q_NULLPTR));
        addplayers_label->setText(QApplication::translate("Dialog", "Add players", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
