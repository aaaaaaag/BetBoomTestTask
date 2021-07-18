//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_IWARNINGTHROWER_H
#define BETBOOMTESTTASK_IWARNINGTHROWER_H

#include "Logic/Exception.h"
#include "QWidget"
class IWarningThrower
{
public:

    virtual void ShowWarning(Exception* ex) = 0;

};

#endif //BETBOOMTESTTASK_IWARNINGTHROWER_H
