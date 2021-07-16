//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_ICONNECTMEDIATOR_H
#define BETBOOMTESTTASK_ICONNECTMEDIATOR_H

#include "Qt/MainWindow.h"

class IConnectMediator: public QObject{
public:

    virtual void connectSetStartPoint(QPushButton *button) = 0;
    virtual void connectSetEndPoint(QPushButton *button) = 0;
    virtual void connectGetResultPix(QPushButton *button) = 0;
    virtual void connectGetResultMM(QPushButton* button) = 0;

signals:

    void setStartPoint();
    void setEndPoint();
    void getResultPix();
    void getResultMM();

};


#endif //BETBOOMTESTTASK_ICONNECTMEDIATOR_H
