//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_EXCEPTION_H
#define BETBOOMTESTTASK_EXCEPTION_H

#include <utility>

#include "string"

class Exception {
    explicit Exception(std::string exception)
    {
        m_exception =  std::move(exception);
    };

    std::string getError()
    {
        return m_exception;
    };

private:

    std::string m_exception;
};

class WrongChooseDotException: public Exception
{

};


#endif //BETBOOMTESTTASK_EXCEPTION_H
