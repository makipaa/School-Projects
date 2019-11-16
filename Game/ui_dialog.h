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
    QPushButton *acceptButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLCDNumber *lcdMapSize;
    QLabel *headingLabel;
    QSlider *mapSizeSlider;
    QLabel *mapLabel;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *nameLabel;
    QLabel *color_label;
    QLineEdit *nameInput;
    QLabel *addplayers_label;
    QComboBox *comboBox;
    QPushButton *addPlayersButton;
    QLabel *infoLabel;
    QLabel *showPlayersLabel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(418, 356);
        acceptButton = new QPushButton(Dialog);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(330, 320, 84, 28));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 401, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lcdMapSize = new QLCDNumber(gridLayoutWidget);
        lcdMapSize->setObjectName(QStringLiteral("lcdMapSize"));

        gridLayout->addWidget(lcdMapSize, 4, 2, 1, 1);

        headingLabel = new QLabel(gridLayoutWidget);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));

        gridLayout->addWidget(headingLabel, 4, 0, 1, 1);

        mapSizeSlider = new QSlider(gridLayoutWidget);
        mapSizeSlider->setObjectName(QStringLiteral("mapSizeSlider"));
        mapSizeSlider->setMinimum(10);
        mapSizeSlider->setMaximum(100);
        mapSizeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(mapSizeSlider, 4, 1, 1, 1);

        mapLabel = new QLabel(gridLayoutWidget);
        mapLabel->setObjectName(QStringLiteral("mapLabel"));

        gridLayout->addWidget(mapLabel, 1, 0, 1, 3, Qt::AlignHCenter);

        gridLayoutWidget_2 = new QWidget(Dialog);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 110, 401, 116));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(gridLayoutWidget_2);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout_2->addWidget(nameLabel, 1, 0, 1, 1);

        color_label = new QLabel(gridLayoutWidget_2);
        color_label->setObjectName(QStringLiteral("color_label"));

        gridLayout_2->addWidget(color_label, 1, 1, 1, 1);

        nameInput = new QLineEdit(gridLayoutWidget_2);
        nameInput->setObjectName(QStringLiteral("nameInput"));

        gridLayout_2->addWidget(nameInput, 2, 0, 1, 1);

        addplayers_label = new QLabel(gridLayoutWidget_2);
        addplayers_label->setObjectName(QStringLiteral("addplayers_label"));

        gridLayout_2->addWidget(addplayers_label, 0, 0, 1, 2, Qt::AlignHCenter);

        comboBox = new QComboBox(gridLayoutWidget_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 2, 1, 1, 1);

        addPlayersButton = new QPushButton(gridLayoutWidget_2);
        addPlayersButton->setObjectName(QStringLiteral("addPlayersButton"));

        gridLayout_2->addWidget(addPlayersButton, 3, 1, 1, 1);

        infoLabel = new QLabel(gridLayoutWidget_2);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));

        gridLayout_2->addWidget(infoLabel, 3, 0, 1, 1);

        showPlayersLabel = new QLabel(Dialog);
        showPlayersLabel->setObjectName(QStringLiteral("showPlayersLabel"));
        showPlayersLabel->setGeometry(QRect(20, 240, 158, 99));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("Dialog", "Accept", Q_NULLPTR));
        headingLabel->setText(QApplication::translate("Dialog", "Set map size", Q_NULLPTR));
        mapLabel->setText(QApplication::translate("Dialog", "Map size", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("Dialog", "Name", Q_NULLPTR));
        color_label->setText(QApplication::translate("Dialog", "Color", Q_NULLPTR));
        addplayers_label->setText(QApplication::translate("Dialog", "Add players", Q_NULLPTR));
        addPlayersButton->setText(QApplication::translate("Dialog", "Add", Q_NULLPTR));
        infoLabel->setText(QString());
        showPlayersLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
