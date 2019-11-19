/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *endTurnPushButton;
    QFrame *line;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *moneyAmountLabel;
    QLabel *woodLabel;
    QLabel *foodAmountLabel;
    QLabel *stoneLabel;
    QLabel *woodAmountLabel;
    QLabel *moneyLabel;
    QLabel *foodLabel;
    QLabel *stoneAmountLabel;
    QLabel *resourcesLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *roundLabel;
    QLabel *roundNumberLabel;
    QLabel *turnLabel;
    QLabel *turnNameLabel;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QComboBox *buildingsComboBox;
    QPushButton *buildPushButton;
    QLabel *tileInfoLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QStringLiteral("MapWindow"));
        MapWindow->resize(1300, 750);
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(9, 35, 1050, 525));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        endTurnPushButton = new QPushButton(centralwidget);
        endTurnPushButton->setObjectName(QStringLiteral("endTurnPushButton"));
        endTurnPushButton->setGeometry(QRect(1080, 570, 191, 41));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1080, 550, 191, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 570, 951, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        moneyAmountLabel = new QLabel(gridLayoutWidget);
        moneyAmountLabel->setObjectName(QStringLiteral("moneyAmountLabel"));

        gridLayout->addWidget(moneyAmountLabel, 1, 1, 1, 1);

        woodLabel = new QLabel(gridLayoutWidget);
        woodLabel->setObjectName(QStringLiteral("woodLabel"));

        gridLayout->addWidget(woodLabel, 1, 4, 1, 1);

        foodAmountLabel = new QLabel(gridLayoutWidget);
        foodAmountLabel->setObjectName(QStringLiteral("foodAmountLabel"));

        gridLayout->addWidget(foodAmountLabel, 1, 3, 1, 1);

        stoneLabel = new QLabel(gridLayoutWidget);
        stoneLabel->setObjectName(QStringLiteral("stoneLabel"));

        gridLayout->addWidget(stoneLabel, 1, 6, 1, 1);

        woodAmountLabel = new QLabel(gridLayoutWidget);
        woodAmountLabel->setObjectName(QStringLiteral("woodAmountLabel"));

        gridLayout->addWidget(woodAmountLabel, 1, 5, 1, 1);

        moneyLabel = new QLabel(gridLayoutWidget);
        moneyLabel->setObjectName(QStringLiteral("moneyLabel"));

        gridLayout->addWidget(moneyLabel, 1, 0, 1, 1);

        foodLabel = new QLabel(gridLayoutWidget);
        foodLabel->setObjectName(QStringLiteral("foodLabel"));

        gridLayout->addWidget(foodLabel, 1, 2, 1, 1);

        stoneAmountLabel = new QLabel(gridLayoutWidget);
        stoneAmountLabel->setObjectName(QStringLiteral("stoneAmountLabel"));

        gridLayout->addWidget(stoneAmountLabel, 1, 7, 1, 1);

        resourcesLabel = new QLabel(gridLayoutWidget);
        resourcesLabel->setObjectName(QStringLiteral("resourcesLabel"));

        gridLayout->addWidget(resourcesLabel, 0, 0, 1, 8, Qt::AlignHCenter);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 491, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        roundLabel = new QLabel(horizontalLayoutWidget);
        roundLabel->setObjectName(QStringLiteral("roundLabel"));

        horizontalLayout->addWidget(roundLabel);

        roundNumberLabel = new QLabel(horizontalLayoutWidget);
        roundNumberLabel->setObjectName(QStringLiteral("roundNumberLabel"));

        horizontalLayout->addWidget(roundNumberLabel);

        turnLabel = new QLabel(horizontalLayoutWidget);
        turnLabel->setObjectName(QStringLiteral("turnLabel"));

        horizontalLayout->addWidget(turnLabel);

        turnNameLabel = new QLabel(horizontalLayoutWidget);
        turnNameLabel->setObjectName(QStringLiteral("turnNameLabel"));

        horizontalLayout->addWidget(turnNameLabel);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(1100, 50, 131, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        buildingsComboBox = new QComboBox(gridLayoutWidget_2);
        buildingsComboBox->setObjectName(QStringLiteral("buildingsComboBox"));

        gridLayout_2->addWidget(buildingsComboBox, 0, 0, 1, 1);

        buildPushButton = new QPushButton(gridLayoutWidget_2);
        buildPushButton->setObjectName(QStringLiteral("buildPushButton"));

        gridLayout_2->addWidget(buildPushButton, 1, 0, 1, 1);

        tileInfoLabel = new QLabel(centralwidget);
        tileInfoLabel->setObjectName(QStringLiteral("tileInfoLabel"));
        tileInfoLabel->setGeometry(QRect(1080, 160, 201, 131));
        MapWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MapWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 25));
        MapWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MapWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MapWindow->setStatusBar(statusbar);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MainWindow", Q_NULLPTR));
        endTurnPushButton->setText(QApplication::translate("MapWindow", "End Turn", Q_NULLPTR));
        moneyAmountLabel->setText(QString());
        woodLabel->setText(QApplication::translate("MapWindow", "Wood:", Q_NULLPTR));
        foodAmountLabel->setText(QString());
        stoneLabel->setText(QApplication::translate("MapWindow", "Stone:", Q_NULLPTR));
        woodAmountLabel->setText(QString());
        moneyLabel->setText(QApplication::translate("MapWindow", "Money:", Q_NULLPTR));
        foodLabel->setText(QApplication::translate("MapWindow", "Food:", Q_NULLPTR));
        stoneAmountLabel->setText(QString());
        resourcesLabel->setText(QApplication::translate("MapWindow", "Resources", Q_NULLPTR));
        roundLabel->setText(QApplication::translate("MapWindow", "Round:", Q_NULLPTR));
        roundNumberLabel->setText(QString());
        turnLabel->setText(QApplication::translate("MapWindow", "Turn:", Q_NULLPTR));
        turnNameLabel->setText(QString());
        buildPushButton->setText(QApplication::translate("MapWindow", "Build", Q_NULLPTR));
        tileInfoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
