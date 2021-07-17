//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_EXCEPTION_H
#define BETBOOMTESTTASK_EXCEPTION_H

#include <utility>

#include "string"

class Exception: public std::exception{
public:
    Exception() = default;

    explicit Exception(std::string exception)
    {
        m_exception =  std::move(exception);
    };

    std::string getError()
    {
        return m_exception;
    };

protected:

    std::string m_exception;
};

class WrongChooseDotException: public Exception
{
public:
   explicit WrongChooseDotException(std::string ex)
   {
       m_exception = std::move(ex);
   }
};

class FailFindRoadStartException: public Exception
{
public:
    explicit FailFindRoadStartException(std::string ex)
    {
        m_exception = std::move(ex);
    }
};

class FailFindRoadException: public Exception
{
public:
    explicit FailFindRoadException(std::string ex)
    {
        m_exception = std::move(ex);
    }
};

class GetResultWithoutInitDotsException: public Exception
{
public:
    explicit GetResultWithoutInitDotsException(std::string ex)
    {
        m_exception = std::move(ex);
    }
};

#endif //BETBOOMTESTTASK_EXCEPTION_H
