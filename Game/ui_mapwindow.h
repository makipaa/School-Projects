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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *endTurnPushButton;
    QComboBox *recruitsComboBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *tileInfoLabel;
    QComboBox *buildingsComboBox;
    QPushButton *buildPushButton;
    QPushButton *recruitPushButton;
    QGraphicsView *buildingGraphicsView;
    QGridLayout *gridLayout;
    QLabel *stoneAmountLabel;
    QLabel *foodLabel;
    QLabel *foodAmountLabel;
    QLabel *woodAmountLabel;
    QLabel *moneyLabel;
    QLabel *stoneLabel;
    QLabel *resourcesLabel;
    QLabel *moneyAmountLabel;
    QLabel *woodLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *roundLabel;
    QLabel *roundNumberLabel;
    QLabel *turnLabel;
    QLabel *turnNameLabel;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QStringLiteral("MapWindow"));
        MapWindow->resize(1218, 667);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MapWindow->sizePolicy().hasHeightForWidth());
        MapWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        endTurnPushButton = new QPushButton(centralwidget);
        endTurnPushButton->setObjectName(QStringLiteral("endTurnPushButton"));
        sizePolicy.setHeightForWidth(endTurnPushButton->sizePolicy().hasHeightForWidth());
        endTurnPushButton->setSizePolicy(sizePolicy);
        endTurnPushButton->setMinimumSize(QSize(130, 0));

        gridLayout_2->addWidget(endTurnPushButton, 9, 1, 1, 1, Qt::AlignLeft);

        recruitsComboBox = new QComboBox(centralwidget);
        recruitsComboBox->setObjectName(QStringLiteral("recruitsComboBox"));
        sizePolicy.setHeightForWidth(recruitsComboBox->sizePolicy().hasHeightForWidth());
        recruitsComboBox->setSizePolicy(sizePolicy);
        recruitsComboBox->setMinimumSize(QSize(130, 0));

        gridLayout_2->addWidget(recruitsComboBox, 5, 1, 1, 1, Qt::AlignLeft);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);

        tileInfoLabel = new QLabel(centralwidget);
        tileInfoLabel->setObjectName(QStringLiteral("tileInfoLabel"));
        sizePolicy.setHeightForWidth(tileInfoLabel->sizePolicy().hasHeightForWidth());
        tileInfoLabel->setSizePolicy(sizePolicy);
        tileInfoLabel->setMinimumSize(QSize(130, 200));

        gridLayout_2->addWidget(tileInfoLabel, 1, 0, 9, 1, Qt::AlignLeft|Qt::AlignTop);

        buildingsComboBox = new QComboBox(centralwidget);
        buildingsComboBox->setObjectName(QStringLiteral("buildingsComboBox"));
        sizePolicy.setHeightForWidth(buildingsComboBox->sizePolicy().hasHeightForWidth());
        buildingsComboBox->setSizePolicy(sizePolicy);
        buildingsComboBox->setMinimumSize(QSize(130, 0));

        gridLayout_2->addWidget(buildingsComboBox, 2, 1, 1, 1, Qt::AlignLeft);

        buildPushButton = new QPushButton(centralwidget);
        buildPushButton->setObjectName(QStringLiteral("buildPushButton"));
        sizePolicy.setHeightForWidth(buildPushButton->sizePolicy().hasHeightForWidth());
        buildPushButton->setSizePolicy(sizePolicy);
        buildPushButton->setMinimumSize(QSize(130, 0));

        gridLayout_2->addWidget(buildPushButton, 3, 1, 1, 1, Qt::AlignLeft);

        recruitPushButton = new QPushButton(centralwidget);
        recruitPushButton->setObjectName(QStringLiteral("recruitPushButton"));
        sizePolicy.setHeightForWidth(recruitPushButton->sizePolicy().hasHeightForWidth());
        recruitPushButton->setSizePolicy(sizePolicy);
        recruitPushButton->setMinimumSize(QSize(130, 0));

        gridLayout_2->addWidget(recruitPushButton, 6, 1, 1, 1, Qt::AlignLeft);

        buildingGraphicsView = new QGraphicsView(centralwidget);
        buildingGraphicsView->setObjectName(QStringLiteral("buildingGraphicsView"));
        buildingGraphicsView->setEnabled(true);
        sizePolicy.setHeightForWidth(buildingGraphicsView->sizePolicy().hasHeightForWidth());
        buildingGraphicsView->setSizePolicy(sizePolicy);
        buildingGraphicsView->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(buildingGraphicsView, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 5, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stoneAmountLabel = new QLabel(centralwidget);
        stoneAmountLabel->setObjectName(QStringLiteral("stoneAmountLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stoneAmountLabel->sizePolicy().hasHeightForWidth());
        stoneAmountLabel->setSizePolicy(sizePolicy1);
        stoneAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(stoneAmountLabel, 1, 7, 1, 1);

        foodLabel = new QLabel(centralwidget);
        foodLabel->setObjectName(QStringLiteral("foodLabel"));
        sizePolicy1.setHeightForWidth(foodLabel->sizePolicy().hasHeightForWidth());
        foodLabel->setSizePolicy(sizePolicy1);
        foodLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(foodLabel, 1, 2, 1, 1);

        foodAmountLabel = new QLabel(centralwidget);
        foodAmountLabel->setObjectName(QStringLiteral("foodAmountLabel"));
        sizePolicy1.setHeightForWidth(foodAmountLabel->sizePolicy().hasHeightForWidth());
        foodAmountLabel->setSizePolicy(sizePolicy1);
        foodAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(foodAmountLabel, 1, 3, 1, 1);

        woodAmountLabel = new QLabel(centralwidget);
        woodAmountLabel->setObjectName(QStringLiteral("woodAmountLabel"));
        sizePolicy1.setHeightForWidth(woodAmountLabel->sizePolicy().hasHeightForWidth());
        woodAmountLabel->setSizePolicy(sizePolicy1);
        woodAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(woodAmountLabel, 1, 5, 1, 1);

        moneyLabel = new QLabel(centralwidget);
        moneyLabel->setObjectName(QStringLiteral("moneyLabel"));
        sizePolicy1.setHeightForWidth(moneyLabel->sizePolicy().hasHeightForWidth());
        moneyLabel->setSizePolicy(sizePolicy1);
        moneyLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(moneyLabel, 1, 0, 1, 1);

        stoneLabel = new QLabel(centralwidget);
        stoneLabel->setObjectName(QStringLiteral("stoneLabel"));
        sizePolicy1.setHeightForWidth(stoneLabel->sizePolicy().hasHeightForWidth());
        stoneLabel->setSizePolicy(sizePolicy1);
        stoneLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(stoneLabel, 1, 6, 1, 1);

        resourcesLabel = new QLabel(centralwidget);
        resourcesLabel->setObjectName(QStringLiteral("resourcesLabel"));
        sizePolicy1.setHeightForWidth(resourcesLabel->sizePolicy().hasHeightForWidth());
        resourcesLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(resourcesLabel, 0, 0, 1, 8, Qt::AlignHCenter);

        moneyAmountLabel = new QLabel(centralwidget);
        moneyAmountLabel->setObjectName(QStringLiteral("moneyAmountLabel"));
        sizePolicy1.setHeightForWidth(moneyAmountLabel->sizePolicy().hasHeightForWidth());
        moneyAmountLabel->setSizePolicy(sizePolicy1);
        moneyAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(moneyAmountLabel, 1, 1, 1, 1);

        woodLabel = new QLabel(centralwidget);
        woodLabel->setObjectName(QStringLiteral("woodLabel"));
        sizePolicy1.setHeightForWidth(woodLabel->sizePolicy().hasHeightForWidth());
        woodLabel->setSizePolicy(sizePolicy1);
        woodLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(woodLabel, 1, 4, 1, 1);


        gridLayout_3->addLayout(gridLayout, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        roundLabel = new QLabel(centralwidget);
        roundLabel->setObjectName(QStringLiteral("roundLabel"));
        sizePolicy1.setHeightForWidth(roundLabel->sizePolicy().hasHeightForWidth());
        roundLabel->setSizePolicy(sizePolicy1);
        roundLabel->setMinimumSize(QSize(0, 20));
        roundLabel->setMaximumSize(QSize(219, 16777215));

        horizontalLayout_2->addWidget(roundLabel);

        roundNumberLabel = new QLabel(centralwidget);
        roundNumberLabel->setObjectName(QStringLiteral("roundNumberLabel"));
        sizePolicy1.setHeightForWidth(roundNumberLabel->sizePolicy().hasHeightForWidth());
        roundNumberLabel->setSizePolicy(sizePolicy1);
        roundNumberLabel->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(roundNumberLabel);

        turnLabel = new QLabel(centralwidget);
        turnLabel->setObjectName(QStringLiteral("turnLabel"));
        sizePolicy1.setHeightForWidth(turnLabel->sizePolicy().hasHeightForWidth());
        turnLabel->setSizePolicy(sizePolicy1);
        turnLabel->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(turnLabel);

        turnNameLabel = new QLabel(centralwidget);
        turnNameLabel->setObjectName(QStringLiteral("turnNameLabel"));
        sizePolicy1.setHeightForWidth(turnNameLabel->sizePolicy().hasHeightForWidth());
        turnNameLabel->setSizePolicy(sizePolicy1);
        turnNameLabel->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(turnNameLabel);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        graphicsView->setMinimumSize(QSize(200, 100));
        graphicsView->setMaximumSize(QSize(999999, 999999));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setLineWidth(0);

        gridLayout_3->addWidget(graphicsView, 1, 0, 1, 1);

        MapWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MapWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1218, 25));
        MapWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MapWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MapWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MapWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MapWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MapWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MapWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MainWindow", Q_NULLPTR));
        endTurnPushButton->setText(QApplication::translate("MapWindow", "End Turn", Q_NULLPTR));
        tileInfoLabel->setText(QString());
        buildPushButton->setText(QApplication::translate("MapWindow", "Build", Q_NULLPTR));
        recruitPushButton->setText(QApplication::translate("MapWindow", "Recruit", Q_NULLPTR));
        stoneAmountLabel->setText(QString());
        foodLabel->setText(QApplication::translate("MapWindow", "Food:", Q_NULLPTR));
        foodAmountLabel->setText(QString());
        woodAmountLabel->setText(QString());
        moneyLabel->setText(QApplication::translate("MapWindow", "Money:", Q_NULLPTR));
        stoneLabel->setText(QApplication::translate("MapWindow", "Stone:", Q_NULLPTR));
        resourcesLabel->setText(QApplication::translate("MapWindow", "Resources", Q_NULLPTR));
        moneyAmountLabel->setText(QString());
        woodLabel->setText(QApplication::translate("MapWindow", "Wood:", Q_NULLPTR));
        roundLabel->setText(QApplication::translate("MapWindow", "Round:", Q_NULLPTR));
        roundNumberLabel->setText(QString());
        turnLabel->setText(QApplication::translate("MapWindow", "Turn:", Q_NULLPTR));
        turnNameLabel->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MapWindow", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("MapWindow", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
