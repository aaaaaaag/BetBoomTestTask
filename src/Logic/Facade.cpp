//
// Created by denis on 18.07.2021.
//

#include "Logic/Facade.h"

#include <utility>
#include <Qt/WarningThrower.h>
#include "Logic/Commands/CommandGetResultMM.h"
#include "Logic/Commands/CommandGetResultPix.h"
#include "Logic/Commands/CommandSetEndPoint.h"
#include "Logic/Commands/CommandSetStartPoint.h"
#include "Logic/Exception.h"

Facade::Facade(std::shared_ptr<IMatHandler> matHandler, IImageCursorController* cursorController, QLabel *label):
        m_pMatHandler(std::move(matHandler)),
        m_pResLabel(label),
        m_pCursorController(cursorController)
{
}

void Facade::setStartDot() {
    auto command = std::make_shared<CommandSetStartPoint>(m_pCursorController);
    command->execute();
}

void Facade::setEndDot() {
    auto command = std::make_shared<CommandSetEndPoint>(m_pCursorController);
    command->execute();
}

void Facade::getResultPix() {
    try {
        int res = 0;
        auto command = std::make_shared<CommandGetResultPix>(m_pMatHandler, res);
        command->execute();

        m_pResLabel->setText(std::to_string(res).data());
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }
}

void Facade::getResultMM() {
    try {
        double res = 0;
        auto command = std::make_shared<CommandGetResultMM>(m_pMatHandler, res);
        command->execute();

        m_pResLabel->setText(std::to_string(res).data());
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }
}

void Facade::setLabel(QLabel *label) {
    m_pResLabel = label;
}


