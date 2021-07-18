//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_COMMANDGETRESULTMM_H
#define BETBOOMTESTTASK_COMMANDGETRESULTMM_H

#include "IButtonCommand.h"
#include "Logic/OpenCV/IMatHandler.h"
#include "memory"


class CommandGetResultMM: public IButtonCommand{
public:

    CommandGetResultMM(std::shared_ptr<IMatHandler> matHandler, double &res);

    void execute() override;

private:

    std::shared_ptr<IMatHandler> m_pMatHandler;
    double *m_res;

};


#endif //BETBOOMTESTTASK_COMMANDGETRESULTMM_H
