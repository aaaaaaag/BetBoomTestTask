//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_IFACADE_H
#define BETBOOMTESTTASK_IFACADE_H

#include "memory"

class IFacade
{
public:

    virtual ~IFacade() = default;

    virtual void setStartDot() = 0;
    virtual void setEndDot() = 0;
    virtual void getResultPix() = 0;
    virtual void getResultMM() = 0;

};

#endif //BETBOOMTESTTASK_IFACADE_H
