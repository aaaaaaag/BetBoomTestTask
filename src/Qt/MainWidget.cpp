//
// Created by denis on 16.07.2021.
//

#include "Qt/MainWidget.h"
#include <utility>
#include <iostream>
#include "Qt/ConnectMediator.h"
#include "Logic/Exception.h"
#include "Qt/WarningThrower.h"
#include "Logic/Commands/CommandGetResultPix.h"
#include "Logic/Commands/CommandGetResultMM.h"


MainWidget::MainWidget(QLabel* label, IConnectMediator* mediator, std::shared_ptr<IMatHandler> matHandler, QWidget *parent): QMainWindow(parent),
                                                              ui(new Ui::MainWindow),
                                                              m_pMatHandler(std::move(matHandler)){
    //ui->image = label;

    ui->setupUi(this);
    std::cout << "Before main: (" << this->width() << ", " << this->height() << ")\n";
    ui->horizontalLayout->addWidget(label);
    //this->setFixedSize(1200, 900);
    std::cout << "After label: (" << label->width() << ", " << label->height() << ")\n";
    std::cout << "After main: (" << this->width() << ", " << this->height() << ")\n";
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
        int res;
        auto command = std::make_shared<CommandGetResultPix>(m_pMatHandler, res);
        command->execute();

        ui->result->setText(std::to_string(res).data());
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }
}

void MainWidget::getResMM() {
    try {
        double res;
        auto command = std::make_shared<CommandGetResultMM>(m_pMatHandler, res);
        command->execute();

        ui->result->setText(std::to_string(res).data());
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }
}
