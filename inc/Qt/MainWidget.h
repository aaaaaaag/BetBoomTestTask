//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_MAINWIDGET_H
#define BETBOOMTESTTASK_MAINWIDGET_H

#include "Qt/MainWindow.h"
#include <qt5/QtWidgets/QMainWindow>
#include "string"
#include "Qt/IConnectMediator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWidget: public  QMainWindow {

    Q_OBJECT

public:

    explicit MainWidget(QLabel* label, IConnectMediator* mediator, QWidget *parent = nullptr);
    ~MainWidget() override;

protected:


private:

    Ui::MainWindow* ui;


};


#endif //BETBOOMTESTTASK_MAINWIDGET_H
