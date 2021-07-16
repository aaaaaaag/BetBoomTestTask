//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_CONNECTMEDIATOR_H
#define BETBOOMTESTTASK_CONNECTMEDIATOR_H

#include "IConnectMediator.h"
class ConnectMediator: public IConnectMediator{
public:

    void connectSetStartPoint(QPushButton *button) override;
    void connectSetEndPoint(QPushButton *button) override;
    void connectGetResultPix(QPushButton *button) override;
    void connectGetResultMM(QPushButton *button) override;

public slots:

    void emitSetStartPoint();
    void emitSetEndPoint();
    void emitGetResultPix();
    void emitGetResultMM();

};


#endif //BETBOOMTESTTASK_CONNECTMEDIATOR_H
