//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_MAINWIDGET_H
#define BETBOOMTESTTASK_MAINWIDGET_H

#include "Qt/MainWindow.h"
#include <qt5/QtWidgets/QMainWindow>
#include "string"
#include "memory"
#include "FacadeSlotWrapper.h"
#include "QLabel"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWidget: public  QMainWindow {

    Q_OBJECT

public:

    explicit MainWidget(QLabel* label, std::shared_ptr<FacadeSlotWrapper> facade);
    ~MainWidget() override;

private:

    void connectActionsToUi();
    std::shared_ptr<FacadeSlotWrapper> m_pFacade;
    Ui::MainWindow* ui;


};


#endif //BETBOOMTESTTASK_MAINWIDGET_H
