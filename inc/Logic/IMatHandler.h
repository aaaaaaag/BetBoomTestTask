//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_IMATHANDLER_H
#define BETBOOMTESTTASK_IMATHANDLER_H

#include "QPoint"

class IMatHandler
{
public:

    virtual ~IMatHandler() = default;
    virtual void SetStartDot(QPoint dot) = 0;
    virtual void SetEndDot(QPoint dot) = 0;
    virtual int GetResultPix() = 0;
    virtual int GetResultMM() = 0;
};

#endif //BETBOOMTESTTASK_IMATHANDLER_H
