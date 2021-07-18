//
// Created by denis on 18.07.2021.
//

#ifndef BETBOOMTESTTASK_COMMANDGETRESULTPIX_H
#define BETBOOMTESTTASK_COMMANDGETRESULTPIX_H

#include "IButtonCommand.h"
#include "Logic/IMatHandler.h"
#include "memory"

class CommandGetResultPix: public IButtonCommand{
public:

    CommandGetResultPix(std::shared_ptr<IMatHandler> matHandler, int &res);

    void execute() override;

private:

    std::shared_ptr<IMatHandler> m_pMatHandler;
    int *m_res;

};


#endif //BETBOOMTESTTASK_COMMANDGETRESULTPIX_H
