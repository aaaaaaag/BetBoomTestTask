//
// Created by denis on 16.07.2021.
//

#include "Qt/ConnectMediator.h"

void ConnectMediator::emitSetStartPoint() {
    emit setStartPoint();
}

void ConnectMediator::emitSetEndPoint() {
    emit setEndPoint();
}

void ConnectMediator::emitGetResultPix() {
    emit getResultPix();
}

void ConnectMediator::emitGetResultMM() {
    emit getResultMM();
}

void ConnectMediator::connectSetStartPoint(QPushButton *button) {
    connect(button, SIGNAL(clicked()), this, SLOT(emitSetStartPoint()));
}

void ConnectMediator::connectSetEndPoint(QPushButton *button) {
    connect(button, SIGNAL(clicked()), this, SLOT(emitSetEndPoint()));
}

void ConnectMediator::connectGetResultPix(QPushButton *button) {
    connect(button, SIGNAL(clicked()), this, SLOT(emitGetResultPix()));
}

void ConnectMediator::connectGetResultMM(QPushButton *button) {
    connect(button, SIGNAL(clicked()), this, SLOT(emitGetResultMM()));
}
