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

    static bool IsDotCorrect(const std::shared_ptr<IOpenCVWrapper>& wrapper, QPoint point, int rad, const cv::Vec3b& searchColor);

    static QPoint GetStartRoadDot(const std::shared_ptr<IOpenCVWrapper>& wrapper, QPoint point, int max_rad, const cv::Vec3b& searchColor);
};


#endif //BETBOOMTESTTASK_DOTCHECKER_H
