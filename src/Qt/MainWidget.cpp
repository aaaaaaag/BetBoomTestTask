//
// Created by denis on 16.07.2021.
//

#include "Qt/MainWidget.h"
#include <utility>
#include "Qt/ConnectMediator.h"
#include "Logic/Exception.h"
#include "Qt/WarningThrower.h"
MainWidget::MainWidget(QLabel* label, IConnectMediator* mediator, std::shared_ptr<IMatHandler> matHandler, QWidget *parent): QMainWindow(parent),
                                                              ui(new Ui::MainWindow),
                                                              m_pMatHandler(std::move(matHandler)){
    //ui->image = label;

    ui->setupUi(this);

    ui->horizontalLayout->addWidget(label);
    this->setFixedSize(1200, 900);
    mediator->connectSetStartPoint(ui->button_set_start_point);
    mediator->connectSetEndPoint(ui->butto_set_end_point);
    mediator->connectGetResultMM(ui->button_get_res_mm);
    mediator->connectGetResultPix(ui->button_get_res_pix);
    connect(mediator, SIGNAL(getResultPix()), this, SLOT(getResPix()));
    connect(mediator, SIGNAL(getResultMM()), this, SLOT(getResMM()));
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::getResPix() {
    try {
        auto res = m_pMatHandler->GetResultPix();
        QString resStr;
        resStr.append(std::to_string(res).data());
        ui->result->setText(resStr);
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }
}

void MainWidget::getResMM() {
    try {
        auto res = m_pMatHandler->GetResultMM();
        QString resStr;
        resStr.append(std::to_string(res).data());
        ui->result->setText(resStr);
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }
}
