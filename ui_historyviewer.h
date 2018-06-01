/********************************************************************************
** Form generated from reading UI file 'historyviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYVIEWER_H
#define UI_HISTORYVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryViewer
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;
    QWidget *tab_3;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *HistoryViewer)
    {
        if (HistoryViewer->objectName().isEmpty())
            HistoryViewer->setObjectName(QStringLiteral("HistoryViewer"));
        HistoryViewer->resize(660, 584);
        tabWidget = new QTabWidget(HistoryViewer);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 642, 503));
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setAutoFillBackground(true);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 640, 480));
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setAutoFillBackground(true);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 21, 337, 428));
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_3->setAutoFillBackground(true);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 21, 337, 428));
        label_3->setFrameShape(QFrame::WinPanel);
        label_3->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab_3, QString());
        pushButton = new QPushButton(HistoryViewer);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 530, 75, 23));

        retranslateUi(HistoryViewer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HistoryViewer);
    } // setupUi

    void retranslateUi(QWidget *HistoryViewer)
    {
        HistoryViewer->setWindowTitle(QApplication::translate("HistoryViewer", "HistoryViewer", 0));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("HistoryViewer", "Handle Photo", 0));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("HistoryViewer", "Transactor", 0));
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("HistoryViewer", "Agent", 0));
        pushButton->setText(QApplication::translate("HistoryViewer", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class HistoryViewer: public Ui_HistoryViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYVIEWER_H
