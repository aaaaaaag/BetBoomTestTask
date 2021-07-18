//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_FACADESLOTWRAPPER_H
#define BETBOOMTESTTASK_FACADESLOTWRAPPER_H

#include "QObject"
#include "IFacade.h"

class FacadeSlotWrapper: public QObject{
Q_OBJECT

public:
    explicit FacadeSlotWrapper(std::shared_ptr<IFacade> facade);

    void setLabel(QLabel* label);

public slots:

    void setStartDot();
    void setEndDot();
    void getResultPix();
    void getResultMM();

private:
    std::shared_ptr<IFacade> m_pFacade;
};


#endif //BETBOOMTESTTASK_FACADESLOTWRAPPER_H
