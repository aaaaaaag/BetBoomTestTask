//
// Created by denis on 17.07.2021.
//

#include "Logic/OpenCV/DotChecker.h"
#include "Logic/Exception.h"

#define EPS 30

uint uintSubtraction(uint a, int b)
{
    if (a < b)
        return 0;
    return a - b;
}

uint uintSum(uint a, int b)
{
    if (a + b > 255)
        return 255;
    return a + b;
}

bool DotChecker::IsDotCorrect(const std::shared_ptr<IOpenCVWrapper>& wrapper, QPoint point, int rad, const cv::Vec3b& searchColor) {
    try {
        GetStartRoadDot(wrapper, point, rad, searchColor);
    }
    catch (Exception& ex)
    {
        return false;
    }
    return true;
}

QPoint DotChecker::GetStartRoadDot(const std::shared_ptr<IOpenCVWrapper> &wrapper, QPoint point, int max_rad, const cv::Vec3b& searchColor) {
    auto x = point.x();
    auto y = point.y();
    QPoint dot;
    bool isFind = false;
    for (int r = 0; r < max_rad && !isFind; r++)
    {
        for (int row = y - r; row <= y + r && !isFind; row++)
        {
            for (int col = x - r; col <= x + r && !isFind; col++)
            {
                auto color = wrapper->getMatPix(col, row);
                uint blue = color.val[0];
                uint green = color.val[1];
                uint red = color.val[2];
                if ((uintSubtraction(searchColor.val[0], EPS) <= blue && blue <= uintSum(searchColor.val[0], EPS)) &&
                    (uintSubtraction(searchColor.val[1], EPS) <= green && green <= uintSum(searchColor.val[1], EPS)) &&
                    (uintSubtraction(searchColor.val[2], EPS) <= red && red <= uintSum(searchColor.val[2], EPS))) {
                    isFind = true;
                    dot = QPoint(col, row);
                }
            }
        }
    }
    if (!isFind)
        throw FailFindRoadStartException("road start not find");
    return dot;
}
