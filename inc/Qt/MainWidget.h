//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_MAINWIDGET_H
#define BETBOOMTESTTASK_MAINWIDGET_H

#include "Qt/MainWindow.h"
#include <qt5/QtWidgets/QMainWindow>
#include "string"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWidget: public  QMainWindow {

    Q_OBJECT

public:

    MainWidget(std::string imgPath, QWidget *parent = nullptr);
    ~MainWidget() override;

protected:


private:

    Ui::MainWindow* ui;


};


#endif //BETBOOMTESTTASK_MAINWIDGET_H
