//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_DOTCHECKER_H
#define BETBOOMTESTTASK_DOTCHECKER_H

#include "QPoint"
#include "IOpenCVWrapper.h"
#include "utility"
class DotChecker {
public:

    static bool IsDotCorrect(const std::shared_ptr<IOpenCVWrapper>& wrapper, QPoint point, int rad);

};


#endif //BETBOOMTESTTASK_DOTCHECKER_H
