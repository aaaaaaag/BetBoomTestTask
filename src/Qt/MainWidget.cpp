//
// Created by denis on 16.07.2021.
//

#include "Qt/MainWidget.h"
#include "Qt/ConnectMediator.h"

MainWidget::MainWidget(QLabel* label, IConnectMediator* mediator, QWidget *parent): QMainWindow(parent),
                                                              ui(new Ui::MainWindow) {
    //ui->image = label;

    ui->setupUi(this);

    ui->horizontalLayout->addWidget(label);
    this->setFixedSize(1200, 900);
    mediator->connectSetStartPoint(ui->button_set_start_point);
    mediator->connectSetEndPoint(ui->butto_set_end_point);
    mediator->connectGetResultMM(ui->button_get_res_mm);
    mediator->connectGetResultPix(ui->button_get_res_pix);
}

MainWidget::~MainWidget() {
    delete ui;
}
