//
// Created by denis on 18.07.2021.
//

#include "Logic/Commands/CommandGetResultMM.h"
#include <utility>

CommandGetResultMM::CommandGetResultMM(std::shared_ptr<IMatHandler> matHandler, double &res):
m_res(&res),
m_pMatHandler(std::move(matHandler))
{

}

void CommandGetResultMM::execute() {
    *m_res = m_pMatHandler->GetResultMM();
}
