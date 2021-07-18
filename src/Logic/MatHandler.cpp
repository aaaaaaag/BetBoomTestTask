//
// Created by denis on 17.07.2021.
//

#include "Logic/MatHandler.h"

#include <utility>
#include "Logic/DotChecker.h"
#include "Logic/Exception.h"
#define SEARCH_RAD 15

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
    std::cout << "Start dot setted!!!   " << m_startDot.x() << ' ' << m_startDot.y() << std::endl;
}

void MatHandler::SetEndDot(QPoint dot) {
    if (!DotChecker::IsDotCorrect(m_pWrapper, dot, SEARCH_RAD))
    {
        throw WrongChooseDotException(std::string("end dot incorrect"));
    }
    m_isEndSet = true;
    m_endDot = dot;
    std::cout << "End dot setted!!!   " << m_endDot.x() << ' ' << m_endDot.y() << std::endl;
}

int MatHandler::GetResultPix() {
    if (!m_isStartSet)
        throw GetResultWithoutInitDotsException("start point not set");
    if (!m_isEndSet)
        throw GetResultWithoutInitDotsException("end point not set");
    auto start = DotChecker::GetStartRoadDot(m_pWrapper, m_startDot, SEARCH_RAD);
    auto end = DotChecker::GetStartRoadDot(m_pWrapper, m_endDot, SEARCH_RAD);
    std::cout << "END: (" << end.x() << ", " << end.y() << ")\n";
    auto res = m_pPathSearcher->GetNearestPath(start, end);
    m_isStartSet = false;
    m_isEndSet = false;
    return res;
}

int MatHandler::GetResultMM() {

}
