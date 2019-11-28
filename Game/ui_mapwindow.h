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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *roundLabel;
    QLabel *roundNumberLabel;
    QLabel *turnLabel;
    QLabel *turnNameLabel;
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
    QGridLayout *gridLayout_2;
    QPushButton *endTurnPushButton;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QComboBox *buildingsComboBox;
    QPushButton *buildPushButton;
    QLabel *BuildCostLabel;
    QLabel *label;
    QLabel *BuildCostAmntLabel;
    QGroupBox *groupBox_2;
    QComboBox *recruitsComboBox;
    QPushButton *recruitPushButton;
    QLabel *RecruitCostlabel;
    QLabel *Recruitlabel;
    QLabel *RecruitCostAmntLabel;
    QLabel *tileInfoLabel;
    QLabel *buildingInfoLabel;
    QLabel *gameInfoLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

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
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(200, 100));
        graphicsView->setMaximumSize(QSize(999999, 999999));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setLineWidth(0);

        gridLayout_3->addWidget(graphicsView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        roundLabel = new QLabel(centralwidget);
        roundLabel->setObjectName(QStringLiteral("roundLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(roundLabel->sizePolicy().hasHeightForWidth());
        roundLabel->setSizePolicy(sizePolicy2);
        roundLabel->setMinimumSize(QSize(0, 20));
        roundLabel->setMaximumSize(QSize(219, 16777215));

        horizontalLayout_2->addWidget(roundLabel);

        roundNumberLabel = new QLabel(centralwidget);
        roundNumberLabel->setObjectName(QStringLiteral("roundNumberLabel"));
        sizePolicy2.setHeightForWidth(roundNumberLabel->sizePolicy().hasHeightForWidth());
        roundNumberLabel->setSizePolicy(sizePolicy2);
        roundNumberLabel->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(roundNumberLabel);

        turnLabel = new QLabel(centralwidget);
        turnLabel->setObjectName(QStringLiteral("turnLabel"));
        sizePolicy2.setHeightForWidth(turnLabel->sizePolicy().hasHeightForWidth());
        turnLabel->setSizePolicy(sizePolicy2);
        turnLabel->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(turnLabel);

        turnNameLabel = new QLabel(centralwidget);
        turnNameLabel->setObjectName(QStringLiteral("turnNameLabel"));
        sizePolicy2.setHeightForWidth(turnNameLabel->sizePolicy().hasHeightForWidth());
        turnNameLabel->setSizePolicy(sizePolicy2);
        turnNameLabel->setMinimumSize(QSize(0, 20));

        horizontalLayout_2->addWidget(turnNameLabel);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stoneAmountLabel = new QLabel(centralwidget);
        stoneAmountLabel->setObjectName(QStringLiteral("stoneAmountLabel"));
        sizePolicy2.setHeightForWidth(stoneAmountLabel->sizePolicy().hasHeightForWidth());
        stoneAmountLabel->setSizePolicy(sizePolicy2);
        stoneAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(stoneAmountLabel, 1, 7, 1, 1);

        foodLabel = new QLabel(centralwidget);
        foodLabel->setObjectName(QStringLiteral("foodLabel"));
        sizePolicy2.setHeightForWidth(foodLabel->sizePolicy().hasHeightForWidth());
        foodLabel->setSizePolicy(sizePolicy2);
        foodLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(foodLabel, 1, 2, 1, 1);

        foodAmountLabel = new QLabel(centralwidget);
        foodAmountLabel->setObjectName(QStringLiteral("foodAmountLabel"));
        sizePolicy2.setHeightForWidth(foodAmountLabel->sizePolicy().hasHeightForWidth());
        foodAmountLabel->setSizePolicy(sizePolicy2);
        foodAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(foodAmountLabel, 1, 3, 1, 1);

        woodAmountLabel = new QLabel(centralwidget);
        woodAmountLabel->setObjectName(QStringLiteral("woodAmountLabel"));
        sizePolicy2.setHeightForWidth(woodAmountLabel->sizePolicy().hasHeightForWidth());
        woodAmountLabel->setSizePolicy(sizePolicy2);
        woodAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(woodAmountLabel, 1, 5, 1, 1);

        moneyLabel = new QLabel(centralwidget);
        moneyLabel->setObjectName(QStringLiteral("moneyLabel"));
        sizePolicy2.setHeightForWidth(moneyLabel->sizePolicy().hasHeightForWidth());
        moneyLabel->setSizePolicy(sizePolicy2);
        moneyLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(moneyLabel, 1, 0, 1, 1);

        stoneLabel = new QLabel(centralwidget);
        stoneLabel->setObjectName(QStringLiteral("stoneLabel"));
        sizePolicy2.setHeightForWidth(stoneLabel->sizePolicy().hasHeightForWidth());
        stoneLabel->setSizePolicy(sizePolicy2);
        stoneLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(stoneLabel, 1, 6, 1, 1);

        resourcesLabel = new QLabel(centralwidget);
        resourcesLabel->setObjectName(QStringLiteral("resourcesLabel"));
        sizePolicy2.setHeightForWidth(resourcesLabel->sizePolicy().hasHeightForWidth());
        resourcesLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(resourcesLabel, 0, 0, 1, 8, Qt::AlignHCenter);

        moneyAmountLabel = new QLabel(centralwidget);
        moneyAmountLabel->setObjectName(QStringLiteral("moneyAmountLabel"));
        sizePolicy2.setHeightForWidth(moneyAmountLabel->sizePolicy().hasHeightForWidth());
        moneyAmountLabel->setSizePolicy(sizePolicy2);
        moneyAmountLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(moneyAmountLabel, 1, 1, 1, 1);

        woodLabel = new QLabel(centralwidget);
        woodLabel->setObjectName(QStringLiteral("woodLabel"));
        sizePolicy2.setHeightForWidth(woodLabel->sizePolicy().hasHeightForWidth());
        woodLabel->setSizePolicy(sizePolicy2);
        woodLabel->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(woodLabel, 1, 4, 1, 1);


        gridLayout_3->addLayout(gridLayout, 4, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        endTurnPushButton = new QPushButton(centralwidget);
        endTurnPushButton->setObjectName(QStringLiteral("endTurnPushButton"));
        sizePolicy.setHeightForWidth(endTurnPushButton->sizePolicy().hasHeightForWidth());
        endTurnPushButton->setSizePolicy(sizePolicy);
        endTurnPushButton->setMinimumSize(QSize(130, 0));

        gridLayout_2->addWidget(endTurnPushButton, 4, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(130, 180));
        groupBox->setMaximumSize(QSize(130, 16777215));
        buildingsComboBox = new QComboBox(groupBox);
        buildingsComboBox->setObjectName(QStringLiteral("buildingsComboBox"));
        buildingsComboBox->setGeometry(QRect(0, 20, 130, 28));
        sizePolicy.setHeightForWidth(buildingsComboBox->sizePolicy().hasHeightForWidth());
        buildingsComboBox->setSizePolicy(sizePolicy);
        buildingsComboBox->setMinimumSize(QSize(100, 0));
        buildPushButton = new QPushButton(groupBox);
        buildPushButton->setObjectName(QStringLiteral("buildPushButton"));
        buildPushButton->setGeometry(QRect(0, 50, 130, 28));
        sizePolicy.setHeightForWidth(buildPushButton->sizePolicy().hasHeightForWidth());
        buildPushButton->setSizePolicy(sizePolicy);
        buildPushButton->setMinimumSize(QSize(100, 0));
        BuildCostLabel = new QLabel(groupBox);
        BuildCostLabel->setObjectName(QStringLiteral("BuildCostLabel"));
        BuildCostLabel->setGeometry(QRect(2, 80, 131, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 100, 63, 81));
        BuildCostAmntLabel = new QLabel(groupBox);
        BuildCostAmntLabel->setObjectName(QStringLiteral("BuildCostAmntLabel"));
        BuildCostAmntLabel->setGeometry(QRect(60, 100, 63, 81));

        gridLayout_5->addWidget(groupBox, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(130, 180));
        recruitsComboBox = new QComboBox(groupBox_2);
        recruitsComboBox->setObjectName(QStringLiteral("recruitsComboBox"));
        recruitsComboBox->setGeometry(QRect(0, 20, 130, 28));
        sizePolicy.setHeightForWidth(recruitsComboBox->sizePolicy().hasHeightForWidth());
        recruitsComboBox->setSizePolicy(sizePolicy);
        recruitsComboBox->setMinimumSize(QSize(100, 0));
        recruitPushButton = new QPushButton(groupBox_2);
        recruitPushButton->setObjectName(QStringLiteral("recruitPushButton"));
        recruitPushButton->setGeometry(QRect(0, 50, 131, 28));
        sizePolicy.setHeightForWidth(recruitPushButton->sizePolicy().hasHeightForWidth());
        recruitPushButton->setSizePolicy(sizePolicy);
        recruitPushButton->setMinimumSize(QSize(100, 0));
        RecruitCostlabel = new QLabel(groupBox_2);
        RecruitCostlabel->setObjectName(QStringLiteral("RecruitCostlabel"));
        RecruitCostlabel->setGeometry(QRect(0, 80, 121, 20));
        Recruitlabel = new QLabel(groupBox_2);
        Recruitlabel->setObjectName(QStringLiteral("Recruitlabel"));
        Recruitlabel->setGeometry(QRect(0, 100, 63, 81));
        RecruitCostAmntLabel = new QLabel(groupBox_2);
        RecruitCostAmntLabel->setObjectName(QStringLiteral("RecruitCostAmntLabel"));
        RecruitCostAmntLabel->setGeometry(QRect(60, 100, 63, 81));

        gridLayout_5->addWidget(groupBox_2, 2, 1, 1, 1);

        tileInfoLabel = new QLabel(centralwidget);
        tileInfoLabel->setObjectName(QStringLiteral("tileInfoLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tileInfoLabel->sizePolicy().hasHeightForWidth());
        tileInfoLabel->setSizePolicy(sizePolicy3);
        tileInfoLabel->setMinimumSize(QSize(130, 150));
        tileInfoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(tileInfoLabel, 0, 0, 1, 2);

        buildingInfoLabel = new QLabel(centralwidget);
        buildingInfoLabel->setObjectName(QStringLiteral("buildingInfoLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(buildingInfoLabel->sizePolicy().hasHeightForWidth());
        buildingInfoLabel->setSizePolicy(sizePolicy4);
        buildingInfoLabel->setMinimumSize(QSize(160, 130));
        buildingInfoLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(buildingInfoLabel, 1, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout_5, 0, 0, 1, 2);

        gameInfoLabel = new QLabel(centralwidget);
        gameInfoLabel->setObjectName(QStringLiteral("gameInfoLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(gameInfoLabel->sizePolicy().hasHeightForWidth());
        gameInfoLabel->setSizePolicy(sizePolicy5);
        gameInfoLabel->setMinimumSize(QSize(280, 0));

        gridLayout_2->addWidget(gameInfoLabel, 3, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 0, 2, 5, 1);

        MapWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MapWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1218, 25));
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
        roundLabel->setText(QApplication::translate("MapWindow", "Round:", Q_NULLPTR));
        roundNumberLabel->setText(QString());
        turnLabel->setText(QApplication::translate("MapWindow", "Turn:", Q_NULLPTR));
        turnNameLabel->setText(QString());
        stoneAmountLabel->setText(QString());
        foodLabel->setText(QApplication::translate("MapWindow", "Food:", Q_NULLPTR));
        foodAmountLabel->setText(QString());
        woodAmountLabel->setText(QString());
        moneyLabel->setText(QApplication::translate("MapWindow", "Money:", Q_NULLPTR));
        stoneLabel->setText(QApplication::translate("MapWindow", "Stone:", Q_NULLPTR));
        resourcesLabel->setText(QApplication::translate("MapWindow", "Resources", Q_NULLPTR));
        moneyAmountLabel->setText(QString());
        woodLabel->setText(QApplication::translate("MapWindow", "Wood:", Q_NULLPTR));
        endTurnPushButton->setText(QApplication::translate("MapWindow", "End Turn", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MapWindow", "Buildings", Q_NULLPTR));
        buildPushButton->setText(QApplication::translate("MapWindow", "Build", Q_NULLPTR));
        BuildCostLabel->setText(QApplication::translate("MapWindow", "Build Cost", Q_NULLPTR));
        label->setText(QApplication::translate("MapWindow", "Money:\n"
"Food:\n"
"Wood:\n"
"Stone:", Q_NULLPTR));
        BuildCostAmntLabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MapWindow", "Workers", Q_NULLPTR));
        recruitPushButton->setText(QApplication::translate("MapWindow", "Recruit", Q_NULLPTR));
        RecruitCostlabel->setText(QApplication::translate("MapWindow", "Recruit Cost", Q_NULLPTR));
        Recruitlabel->setText(QApplication::translate("MapWindow", "Money:\n"
"Food:\n"
"Wood:\n"
"Stone:", Q_NULLPTR));
        RecruitCostAmntLabel->setText(QString());
        tileInfoLabel->setText(QString());
        buildingInfoLabel->setText(QString());
        gameInfoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
