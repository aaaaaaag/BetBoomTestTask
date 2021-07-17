//
// Created by denis on 17.07.2021.
//

#include "MatHandler.h"

#include <utility>
#include "DotChecker.h"

#define SEARCH_RAD 7

void MatHandler::SetStartDot(QPoint dot) {
    if (!DotChecker::IsDotCorrect(m_pWrapper, dot, SEARCH_RAD))
    {

    }
    m_isStartSet = true;
    m_startDot = dot;
}

void MatHandler::SetEndDot(QPoint dot) {
    if (!DotChecker::IsDotCorrect(m_pWrapper, dot, SEARCH_RAD))
    {

    }
    m_isEndSet = true;
    m_endDot = dot;
}

MatHandler::MatHandler(std::shared_ptr<IOpenCVWrapper> wrapper): m_pWrapper(std::move(wrapper)) {
}

void MatHandler::GetResultPix() {

}

void MatHandler::GetResultMM() {

}
