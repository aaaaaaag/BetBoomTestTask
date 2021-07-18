//
// Created by denis on 18.07.2021.
//

#include "CommandSetStartPoint.h"

CommandSetStartPoint::CommandSetStartPoint(IImageCursorController *controller):
m_controller(controller)
{
}

void CommandSetStartPoint::execute() {
    m_controller->setState(mouseDoState::setStartDot);
}
