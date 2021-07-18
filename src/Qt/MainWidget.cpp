//
// Created by denis on 16.07.2021.
//

#include "Qt/MainWidget.h"
#include <utility>

MainWidget::MainWidget(QLabel* label, std::shared_ptr<FacadeSlotWrapper> facade):
QMainWindow(nullptr),
ui(new Ui::MainWindow),
m_pFacade(std::move(facade))
{
    ui->setupUi(this);
    ui->horizontalLayout->addWidget(label);
    m_pFacade->setLabel(ui->result);
    connectActionsToUi();
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::connectActionsToUi() {
    connect(ui->button_set_start_point, SIGNAL(clicked()), m_pFacade.get(), SLOT(setStartDot()));
    connect(ui->butto_set_end_point, SIGNAL(clicked()), m_pFacade.get(), SLOT(setEndDot()));
    connect(ui->button_get_res_mm, SIGNAL(clicked()), m_pFacade.get(), SLOT(getResultMM()));
    connect(ui->button_get_res_pix, SIGNAL(clicked()), m_pFacade.get(), SLOT(getResultPix()));
}
