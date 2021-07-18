//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_COMMANDSETENDPOINT_H
#define BETBOOMTESTTASK_COMMANDSETENDPOINT_H

#include "IButtonCommand.h"
#include "Qt/IImageCursorController.h"

class CommandSetEndPoint: public IButtonCommand {
public:

    explicit CommandSetEndPoint(IImageCursorController* controller);
    void execute() override;

private:

    IImageCursorController* m_controller;
};


#endif //BETBOOMTESTTASK_COMMANDSETENDPOINT_H
