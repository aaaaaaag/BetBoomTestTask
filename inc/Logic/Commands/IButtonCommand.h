//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_IBUTTONCOMMAND_H
#define BETBOOMTESTTASK_IBUTTONCOMMAND_H

class IButtonCommand
{
public:

    virtual ~IButtonCommand() = default;

    virtual void execute() = 0;

};

#endif //BETBOOMTESTTASK_IBUTTONCOMMAND_H
