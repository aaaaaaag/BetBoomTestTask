//
// Created by denis on 16.07.2021.
//

#include "Qt/MainWidget.h"
#include "Qt/ConnectMediator.h"

MainWidget::MainWidget(QLabel* label, QWidget *parent): QMainWindow(parent),
                                                              ui(new Ui::MainWindow) {
    //ui->image = label;

    ui->setupUi(this);

    ui->horizontalLayout->addWidget(label);

    auto connector = new ConnectMediator;
    connector->connectSetStartPoint(ui->button_set_start_point);
    connector->connectSetEndPoint(ui->butto_set_end_point);
    connector->connectGetResultMM(ui->button_get_res_mm);
    connector->connectGetResultPix(ui->button_get_res_pix);
}

MainWidget::~MainWidget() {
    delete ui;
}
