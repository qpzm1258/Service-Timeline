/********************************************************************************
** Form generated from reading UI file 'servicetimelinetable.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICETIMELINETABLE_H
#define UI_SERVICETIMELINETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServiceTimeLineTable
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit_2;
    QDateTimeEdit *dateTimeEdit;
    QTableWidget *tableWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ServiceTimeLineTable)
    {
        if (ServiceTimeLineTable->objectName().isEmpty())
            ServiceTimeLineTable->setObjectName(QStringLiteral("ServiceTimeLineTable"));
        ServiceTimeLineTable->resize(800, 480);
        gridLayoutWidget = new QWidget(ServiceTimeLineTable);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 9, 781, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        dateTimeEdit_2 = new QDateTimeEdit(gridLayoutWidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setDateTime(QDateTime(QDate(7999, 12, 31), QTime(23, 59, 59)));
        dateTimeEdit_2->setTime(QTime(23, 59, 59));

        gridLayout->addWidget(dateTimeEdit_2, 1, 3, 1, 1);

        dateTimeEdit = new QDateTimeEdit(gridLayoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 1, 1, 1, 1);

        tableWidget = new QTableWidget(ServiceTimeLineTable);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 160, 781, 311));
        horizontalLayoutWidget = new QWidget(ServiceTimeLineTable);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 100, 781, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(ServiceTimeLineTable);

        QMetaObject::connectSlotsByName(ServiceTimeLineTable);
    } // setupUi

    void retranslateUi(QWidget *ServiceTimeLineTable)
    {
        ServiceTimeLineTable->setWindowTitle(QApplication::translate("ServiceTimeLineTable", "History  ", 0));
        label_2->setText(QApplication::translate("ServiceTimeLineTable", "Code", 0));
        label_3->setText(QApplication::translate("ServiceTimeLineTable", "Start Time", 0));
        label->setText(QApplication::translate("ServiceTimeLineTable", "Name", 0));
        label_4->setText(QApplication::translate("ServiceTimeLineTable", "End Time", 0));
        pushButton->setText(QApplication::translate("ServiceTimeLineTable", "Search", 0));
        pushButton_2->setText(QApplication::translate("ServiceTimeLineTable", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class ServiceTimeLineTable: public Ui_ServiceTimeLineTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICETIMELINETABLE_H
