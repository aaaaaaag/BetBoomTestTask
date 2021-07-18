//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_IPATHSEARCHER_H
#define BETBOOMTESTTASK_IPATHSEARCHER_H

#include "QPoint"
#include "vector"
class IPathSearcher
{
public:

    virtual ~IPathSearcher() = default;
    virtual int GetNearestPath(QPoint start, QPoint end) = 0;

};

#endif //BETBOOMTESTTASK_IPATHSEARCHER_H
