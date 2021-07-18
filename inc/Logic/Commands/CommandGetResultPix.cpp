//
// Created by denis on 18.07.2021.
//

#include "CommandGetResultPix.h"

#include <utility>

void CommandGetResultPix::execute() {
    *m_res = m_pMatHandler->GetResultPix();
}

CommandGetResultPix::CommandGetResultPix(std::shared_ptr<IMatHandler> matHandler, int &res):
m_pMatHandler(std::move(matHandler)),
m_res(&res)
{
}
