//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_FACADE_H
#define BETBOOMTESTTASK_FACADE_H

#include "IFacade.h"
#include "IMatHandler.h"
#include "QLabel"
#include "IImageCursorController.h"

class Facade: public IFacade{
public:

    Facade(std::shared_ptr<IMatHandler> matHandler, IImageCursorController* cursorController, QLabel *label);

    void setStartDot() override;

    void setEndDot() override;

    void getResultPix() override;

    void getResultMM() override;

    void setLabel(QLabel *label) override;

private:
    IImageCursorController* m_pCursorController;
    std::shared_ptr<IMatHandler> m_pMatHandler;
    QLabel* m_pResLabel;

};


#endif //BETBOOMTESTTASK_FACADE_H
