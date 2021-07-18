//
// Created by denis on 18.07.2021.
//

#include "Logic/Facade.h"

#include <utility>
#include <Qt/WarningThrower.h>
#include "Logic/Commands/CommandGetResultMM.h"
#include "Logic/Commands/CommandGetResultPix.h"
#include "Logic/Exception.h"

void Facade::setStartDot() {

}

void Facade::setEndDot() {

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

Facade::Facade(std::shared_ptr<IMatHandler> matHandler, QLabel *label):
m_pMatHandler(std::move(matHandler)),
m_pResLabel(label)
{
}
