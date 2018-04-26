/********************************************************************************
** Form generated from reading UI file 'TakePhotos.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAKEPHOTOS_H
#define UI_TAKEPHOTOS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TakePhotosClass
{
public:
    QAction *actionCamera_1;
    QAction *actionCamera_2;
    QAction *actionCamera_3;
    QAction *actionCamera_4;
    QAction *actionCamera_5;
    QAction *actionText_Settings;
    QAction *actionFont_Settings;
    QAction *actionServer_Setting;
    QAction *actionHistory;
    QWidget *centralWidget;
    QLabel *cameraLabel;
    QTabWidget *tabWidget;
    QWidget *transactorTab;
    QPushButton *cleanBtn;
    QLabel *label_3;
    QPushButton *readInfoBtn;
    QLineEdit *nameInput;
    QLabel *cardPhtotoTextLabel_2;
    QLabel *cardPhotoLabel;
    QLabel *label_4;
    QLineEdit *IDCardNumInput;
    QWidget *agentTab;
    QLabel *agentPhotoLabel;
    QLabel *cardPhtotoTextLabel;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *agentNameInput;
    QPushButton *readAgentBtn;
    QPushButton *cleanAgentBtn;
    QLineEdit *agentNumInput;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *takePhotoBtn;
    QPushButton *cleanAllBtn;
    QPushButton *submitBtn;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuSwitch_Camera;
    QMenu *menuTools;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TakePhotosClass)
    {
        if (TakePhotosClass->objectName().isEmpty())
            TakePhotosClass->setObjectName(QStringLiteral("TakePhotosClass"));
        TakePhotosClass->resize(803, 600);
        TakePhotosClass->setLocale(QLocale(QLocale::Armenian, QLocale::Armenia));
        actionCamera_1 = new QAction(TakePhotosClass);
        actionCamera_1->setObjectName(QStringLiteral("actionCamera_1"));
        actionCamera_1->setCheckable(true);
        actionCamera_1->setChecked(true);
        actionCamera_2 = new QAction(TakePhotosClass);
        actionCamera_2->setObjectName(QStringLiteral("actionCamera_2"));
        actionCamera_2->setCheckable(true);
        actionCamera_3 = new QAction(TakePhotosClass);
        actionCamera_3->setObjectName(QStringLiteral("actionCamera_3"));
        actionCamera_3->setCheckable(true);
        actionCamera_4 = new QAction(TakePhotosClass);
        actionCamera_4->setObjectName(QStringLiteral("actionCamera_4"));
        actionCamera_4->setCheckable(true);
        actionCamera_5 = new QAction(TakePhotosClass);
        actionCamera_5->setObjectName(QStringLiteral("actionCamera_5"));
        actionCamera_5->setCheckable(true);
        actionText_Settings = new QAction(TakePhotosClass);
        actionText_Settings->setObjectName(QStringLiteral("actionText_Settings"));
        actionFont_Settings = new QAction(TakePhotosClass);
        actionFont_Settings->setObjectName(QStringLiteral("actionFont_Settings"));
        actionServer_Setting = new QAction(TakePhotosClass);
        actionServer_Setting->setObjectName(QStringLiteral("actionServer_Setting"));
        actionHistory = new QAction(TakePhotosClass);
        actionHistory->setObjectName(QStringLiteral("actionHistory"));
        centralWidget = new QWidget(TakePhotosClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cameraLabel = new QLabel(centralWidget);
        cameraLabel->setObjectName(QStringLiteral("cameraLabel"));
        cameraLabel->setGeometry(QRect(0, -1, 600, 481));
        cameraLabel->setAutoFillBackground(true);
        cameraLabel->setLocale(QLocale(QLocale::Armenian, QLocale::Armenia));
        cameraLabel->setFrameShape(QFrame::Panel);
        cameraLabel->setFrameShadow(QFrame::Sunken);
        cameraLabel->setLineWidth(2);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(600, 0, 200, 481));
        QFont font;
        font.setPointSize(9);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        transactorTab = new QWidget();
        transactorTab->setObjectName(QStringLiteral("transactorTab"));
        transactorTab->setAutoFillBackground(true);
        cleanBtn = new QPushButton(transactorTab);
        cleanBtn->setObjectName(QStringLiteral("cleanBtn"));
        cleanBtn->setGeometry(QRect(62, 390, 75, 23));
        label_3 = new QLabel(transactorTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 250, 180, 16));
        label_3->setAlignment(Qt::AlignCenter);
        readInfoBtn = new QPushButton(transactorTab);
        readInfoBtn->setObjectName(QStringLiteral("readInfoBtn"));
        readInfoBtn->setGeometry(QRect(62, 340, 75, 23));
        nameInput = new QLineEdit(transactorTab);
        nameInput->setObjectName(QStringLiteral("nameInput"));
        nameInput->setGeometry(QRect(43, 280, 113, 20));
        QFont font1;
        font1.setPointSize(10);
        nameInput->setFont(font1);
        nameInput->setAlignment(Qt::AlignCenter);
        cardPhtotoTextLabel_2 = new QLabel(transactorTab);
        cardPhtotoTextLabel_2->setObjectName(QStringLiteral("cardPhtotoTextLabel_2"));
        cardPhtotoTextLabel_2->setGeometry(QRect(10, 10, 180, 16));
        cardPhtotoTextLabel_2->setAlignment(Qt::AlignCenter);
        cardPhotoLabel = new QLabel(transactorTab);
        cardPhotoLabel->setObjectName(QStringLiteral("cardPhotoLabel"));
        cardPhotoLabel->setGeometry(QRect(49, 35, 102, 126));
        cardPhotoLabel->setFrameShape(QFrame::Panel);
        cardPhotoLabel->setFrameShadow(QFrame::Sunken);
        cardPhotoLabel->setLineWidth(2);
        cardPhotoLabel->setMidLineWidth(0);
        label_4 = new QLabel(transactorTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 180, 12));
        label_4->setAlignment(Qt::AlignCenter);
        IDCardNumInput = new QLineEdit(transactorTab);
        IDCardNumInput->setObjectName(QStringLiteral("IDCardNumInput"));
        IDCardNumInput->setGeometry(QRect(20, 210, 160, 20));
        IDCardNumInput->setFont(font1);
        IDCardNumInput->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(transactorTab, QString());
        agentTab = new QWidget();
        agentTab->setObjectName(QStringLiteral("agentTab"));
        agentTab->setAutoFillBackground(true);
        agentTab->setLocale(QLocale(QLocale::Armenian, QLocale::Armenia));
        agentPhotoLabel = new QLabel(agentTab);
        agentPhotoLabel->setObjectName(QStringLiteral("agentPhotoLabel"));
        agentPhotoLabel->setGeometry(QRect(49, 35, 102, 126));
        agentPhotoLabel->setFrameShape(QFrame::Panel);
        agentPhotoLabel->setFrameShadow(QFrame::Sunken);
        agentPhotoLabel->setLineWidth(2);
        cardPhtotoTextLabel = new QLabel(agentTab);
        cardPhtotoTextLabel->setObjectName(QStringLiteral("cardPhtotoTextLabel"));
        cardPhtotoTextLabel->setGeometry(QRect(10, 10, 180, 16));
        cardPhtotoTextLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(agentTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 180, 180, 12));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(agentTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 250, 180, 16));
        label_2->setAlignment(Qt::AlignCenter);
        agentNameInput = new QLineEdit(agentTab);
        agentNameInput->setObjectName(QStringLiteral("agentNameInput"));
        agentNameInput->setGeometry(QRect(43, 280, 113, 20));
        agentNameInput->setFont(font1);
        agentNameInput->setAlignment(Qt::AlignCenter);
        readAgentBtn = new QPushButton(agentTab);
        readAgentBtn->setObjectName(QStringLiteral("readAgentBtn"));
        readAgentBtn->setGeometry(QRect(62, 340, 75, 23));
        cleanAgentBtn = new QPushButton(agentTab);
        cleanAgentBtn->setObjectName(QStringLiteral("cleanAgentBtn"));
        cleanAgentBtn->setGeometry(QRect(62, 390, 75, 23));
        agentNumInput = new QLineEdit(agentTab);
        agentNumInput->setObjectName(QStringLiteral("agentNumInput"));
        agentNumInput->setGeometry(QRect(20, 210, 160, 20));
        agentNumInput->setFont(font1);
        agentNumInput->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(agentTab, QString());
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(450, 480, 341, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        takePhotoBtn = new QPushButton(horizontalLayoutWidget);
        takePhotoBtn->setObjectName(QStringLiteral("takePhotoBtn"));

        horizontalLayout->addWidget(takePhotoBtn);

        cleanAllBtn = new QPushButton(horizontalLayoutWidget);
        cleanAllBtn->setObjectName(QStringLiteral("cleanAllBtn"));
        cleanAllBtn->setEnabled(true);

        horizontalLayout->addWidget(cleanAllBtn);

        submitBtn = new QPushButton(horizontalLayoutWidget);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));

        horizontalLayout->addWidget(submitBtn);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(100, 480, 341, 71));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        comboBox_2 = new QComboBox(horizontalLayoutWidget_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);

        TakePhotosClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TakePhotosClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 803, 23));
        menuBar->setAutoFillBackground(true);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setAutoFillBackground(true);
        menuSwitch_Camera = new QMenu(menu);
        menuSwitch_Camera->setObjectName(QStringLiteral("menuSwitch_Camera"));
        menuSwitch_Camera->setEnabled(true);
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        TakePhotosClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(TakePhotosClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TakePhotosClass->setStatusBar(statusBar);
        QWidget::setTabOrder(comboBox_2, takePhotoBtn);
        QWidget::setTabOrder(takePhotoBtn, IDCardNumInput);
        QWidget::setTabOrder(IDCardNumInput, nameInput);
        QWidget::setTabOrder(nameInput, readInfoBtn);
        QWidget::setTabOrder(readInfoBtn, cleanBtn);
        QWidget::setTabOrder(cleanBtn, tabWidget);
        QWidget::setTabOrder(tabWidget, agentNumInput);
        QWidget::setTabOrder(agentNumInput, agentNameInput);
        QWidget::setTabOrder(agentNameInput, readAgentBtn);
        QWidget::setTabOrder(readAgentBtn, cleanAgentBtn);
        QWidget::setTabOrder(cleanAgentBtn, cleanAllBtn);
        QWidget::setTabOrder(cleanAllBtn, submitBtn);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menu->addAction(menuSwitch_Camera->menuAction());
        menu->addAction(actionFont_Settings);
        menu->addAction(actionServer_Setting);
        menuTools->addAction(actionHistory);

        retranslateUi(TakePhotosClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TakePhotosClass);
    } // setupUi

    void retranslateUi(QMainWindow *TakePhotosClass)
    {
        TakePhotosClass->setWindowTitle(QApplication::translate("TakePhotosClass", "TakePhotos", 0));
        actionCamera_1->setText(QApplication::translate("TakePhotosClass", "Camera 1", 0));
        actionCamera_2->setText(QApplication::translate("TakePhotosClass", "Camera 2", 0));
        actionCamera_3->setText(QApplication::translate("TakePhotosClass", "Camera 3", 0));
        actionCamera_4->setText(QApplication::translate("TakePhotosClass", "Camera 4", 0));
        actionCamera_5->setText(QApplication::translate("TakePhotosClass", "Camera 5", 0));
        actionText_Settings->setText(QApplication::translate("TakePhotosClass", "Text Settings", 0));
        actionFont_Settings->setText(QApplication::translate("TakePhotosClass", "Font Settings", 0));
        actionServer_Setting->setText(QApplication::translate("TakePhotosClass", "Server Setting", 0));
        actionHistory->setText(QApplication::translate("TakePhotosClass", "History", 0));
        cameraLabel->setText(QString());
        cleanBtn->setText(QApplication::translate("TakePhotosClass", "Clean", 0));
        label_3->setText(QApplication::translate("TakePhotosClass", "Name", 0));
        readInfoBtn->setText(QApplication::translate("TakePhotosClass", "Read IDCard", 0));
        nameInput->setText(QString());
        cardPhtotoTextLabel_2->setText(QApplication::translate("TakePhotosClass", "Photo", 0));
        cardPhotoLabel->setText(QString());
        label_4->setText(QApplication::translate("TakePhotosClass", "ID Number", 0));
        tabWidget->setTabText(tabWidget->indexOf(transactorTab), QApplication::translate("TakePhotosClass", "Transactor", 0));
        agentPhotoLabel->setText(QString());
        cardPhtotoTextLabel->setText(QApplication::translate("TakePhotosClass", "Photo", 0));
        label->setText(QApplication::translate("TakePhotosClass", "ID Number", 0));
        label_2->setText(QApplication::translate("TakePhotosClass", "Name", 0));
        agentNameInput->setText(QString());
        readAgentBtn->setText(QApplication::translate("TakePhotosClass", "Read IDCard", 0));
        cleanAgentBtn->setText(QApplication::translate("TakePhotosClass", "Clean", 0));
        tabWidget->setTabText(tabWidget->indexOf(agentTab), QApplication::translate("TakePhotosClass", "Agent", 0));
        takePhotoBtn->setText(QApplication::translate("TakePhotosClass", "Take Photo", 0));
        cleanAllBtn->setText(QApplication::translate("TakePhotosClass", "Clean All", 0));
        submitBtn->setText(QApplication::translate("TakePhotosClass", "Submit", 0));
        label_5->setText(QApplication::translate("TakePhotosClass", "Type", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("TakePhotosClass", "Reset IC card password", 0)
         << QApplication::translate("TakePhotosClass", "IC card relieves the loss", 0)
         << QApplication::translate("TakePhotosClass", "Card - free settlement record", 0)
        );
        menu->setTitle(QApplication::translate("TakePhotosClass", "Settings", 0));
        menuSwitch_Camera->setTitle(QApplication::translate("TakePhotosClass", "Switch Camera", 0));
        menuTools->setTitle(QApplication::translate("TakePhotosClass", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class TakePhotosClass: public Ui_TakePhotosClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAKEPHOTOS_H
