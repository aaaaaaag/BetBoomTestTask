/********************************************************************************
** Form generated from reading UI file 'MainWindowyyaUOG.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWYYAUOG_H
#define MAINWINDOWYYAUOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *menu_layout;
    QLabel *label_result;
    QLabel *result;
    QPushButton *button_set_start_point;
    QPushButton *butto_set_end_point;
    QPushButton *button_get_res_pix;
    QPushButton *button_get_res_mm;
    QLabel *image;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1191, 785);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        menu_layout = new QVBoxLayout();
        menu_layout->setSpacing(0);
        menu_layout->setObjectName(QStringLiteral("menu_layout"));
        label_result = new QLabel(centralwidget);
        label_result->setObjectName(QStringLiteral("label_result"));
        label_result->setMaximumSize(QSize(16777215, 50));

        menu_layout->addWidget(label_result);

        result = new QLabel(centralwidget);
        result->setObjectName(QStringLiteral("result"));
        result->setMaximumSize(QSize(16777215, 50));

        menu_layout->addWidget(result);

        button_set_start_point = new QPushButton(centralwidget);
        button_set_start_point->setObjectName(QStringLiteral("button_set_start_point"));
        button_set_start_point->setMinimumSize(QSize(0, 100));

        menu_layout->addWidget(button_set_start_point);

        butto_set_end_point = new QPushButton(centralwidget);
        butto_set_end_point->setObjectName(QStringLiteral("butto_set_end_point"));
        butto_set_end_point->setMinimumSize(QSize(0, 100));

        menu_layout->addWidget(butto_set_end_point);

        button_get_res_pix = new QPushButton(centralwidget);
        button_get_res_pix->setObjectName(QStringLiteral("button_get_res_pix"));
        button_get_res_pix->setMinimumSize(QSize(0, 100));

        menu_layout->addWidget(button_get_res_pix);

        button_get_res_mm = new QPushButton(centralwidget);
        button_get_res_mm->setObjectName(QStringLiteral("button_get_res_mm"));
        button_get_res_mm->setMinimumSize(QSize(0, 100));

        menu_layout->addWidget(button_get_res_mm);


        horizontalLayout->addLayout(menu_layout);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        image = new QLabel(centralwidget);
        image->setObjectName(QStringLiteral("image"));
        image->setMinimumSize(QSize(900, 0));

        gridLayout->addWidget(image, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1191, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_result->setText(QApplication::translate("MainWindow", "Result", nullptr));
        result->setText(QApplication::translate("MainWindow", "0", nullptr));
        button_set_start_point->setText(QApplication::translate("MainWindow", "Set start point", nullptr));
        butto_set_end_point->setText(QApplication::translate("MainWindow", "Set end point", nullptr));
        button_get_res_pix->setText(QApplication::translate("MainWindow", "Get result(pix)", nullptr));
        button_get_res_mm->setText(QApplication::translate("MainWindow", "Get result(mm)", nullptr));
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWYYAUOG_H
