//
// Created by denis on 18.07.2021.
//

#include "FacadeSlotWrapper.h"

#include <utility>

FacadeSlotWrapper::FacadeSlotWrapper(std::shared_ptr<IFacade> facade):
m_pFacade(std::move(facade))
{
}

void FacadeSlotWrapper::setStartDot() {
    m_pFacade->setStartDot();
}

void FacadeSlotWrapper::setEndDot() {
    m_pFacade->setEndDot();
}

void FacadeSlotWrapper::getResultPix() {
    m_pFacade->getResultPix();
}

void FacadeSlotWrapper::getResultMM() {
    m_pFacade->getResultMM();
}

void FacadeSlotWrapper::setLabel(QLabel *label) {
    m_pFacade->setLabel(label);
}
