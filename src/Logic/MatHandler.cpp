//
// Created by denis on 17.07.2021.
//

#include "Logic/MatHandler.h"

#include <utility>
#include "Logic/DotChecker.h"
#include "Logic/Exception.h"
#define SEARCH_RAD 7

MatHandler::MatHandler(std::shared_ptr<IOpenCVWrapper> wrapper): m_pWrapper(std::move(wrapper)) {
}

void MatHandler::SetStartDot(QPoint dot) {
    if (!DotChecker::IsDotCorrect(m_pWrapper, dot, SEARCH_RAD))
    {
        throw WrongChooseDotException(std::string("start dot incorrect"));
    }
    m_isStartSet = true;
    m_startDot = dot;
}

void MatHandler::SetEndDot(QPoint dot) {
    if (!DotChecker::IsDotCorrect(m_pWrapper, dot, SEARCH_RAD))
    {
        throw WrongChooseDotException(std::string("end dot incorrect"));
    }
    m_isEndSet = true;
    m_endDot = dot;
}

void MatHandler::GetResultPix() {

}

void MatHandler::GetResultMM() {

}
