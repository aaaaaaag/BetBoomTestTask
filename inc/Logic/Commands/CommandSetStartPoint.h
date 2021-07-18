//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_COMMANDSETSTARTPOINT_H
#define BETBOOMTESTTASK_COMMANDSETSTARTPOINT_H

#include "IButtonCommand.h"
#include "Logic/IImageCursorController.h"

class CommandSetStartPoint: public IButtonCommand{
public:

    explicit CommandSetStartPoint(IImageCursorController* controller);
    void execute() override;

private:

    IImageCursorController* m_controller;
};


#endif //BETBOOMTESTTASK_COMMANDSETSTARTPOINT_H
