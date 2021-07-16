//
// Created by denis on 16.07.2021.
//

#include "Qt/MainWidget.h"

MainWidget::MainWidget(std::string imgPath, QWidget *parent): QMainWindow(parent),
                                                              ui(new Ui::MainWindow) {
    ui->setupUi(this);

}

MainWidget::~MainWidget() {
    delete ui;
}
