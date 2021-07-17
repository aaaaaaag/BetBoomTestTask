//
// Created by denis on 17.07.2021.
//

#include "Logic/MatHandler.h"

#include <utility>
#include "Logic/DotChecker.h"
#include "Logic/Exception.h"
#define SEARCH_RAD 7

MatHandler::MatHandler(std::shared_ptr<IOpenCVWrapper> wrapper, std::shared_ptr<IPathSearcher> pathSearcher):
m_pWrapper(std::move(wrapper)),
m_pPathSearcher(std::move(pathSearcher)){
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

int MatHandler::GetResultPix() {
    if (!m_isStartSet)
        throw GetResultWithoutInitDotsException("start point not set");
    if (!m_isEndSet)
        throw GetResultWithoutInitDotsException("end point not set");
    return m_pPathSearcher->GetNearestPath(m_startDot, m_endDot);
}

int MatHandler::GetResultMM() {

}
