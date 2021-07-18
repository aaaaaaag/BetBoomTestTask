//
// Created by denis on 17.07.2021.
//

#include "Logic/OpenCV/DotChecker.h"
#include "Logic/Exception.h"
bool DotChecker::IsDotCorrect(const std::shared_ptr<IOpenCVWrapper>& wrapper, QPoint point, int rad) {
    auto x = point.x();
    auto y = point.y();
    cv::Vec3b searchColor = {0, 0, 255};
    bool isFind = false;
    for (int r = 0; r < rad && !isFind; r++)
    {
        for (int row = y - r; row <= y + r && !isFind; row++)
        {
            for (int col = x - r; col <= x + r && !isFind; col++)
            {
                auto color = wrapper->getMatPix(col, row);
                uint blue = color.val[0];
                uint green = color.val[1];
                uint red = color.val[2];
                if ((searchColor.val[0] <= blue && blue <= searchColor.val[0] + 30) &&
                    (searchColor.val[1] <= green && green <= searchColor.val[1] + 30) &&
                    (searchColor.val[2] - 30 <= red && red <= searchColor.val[2])) {
                    isFind = true;
                }
            }
        }
    }
    return isFind;
}

QPoint DotChecker::GetStartRoadDot(const std::shared_ptr<IOpenCVWrapper> &wrapper, QPoint point, int max_rad) {
    auto x = point.x();
    auto y = point.y();
    cv::Vec3b searchColor = {0, 0, 0};
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
                if ((searchColor.val[0] <= blue && blue <= searchColor.val[0] + 50) &&
                    (searchColor.val[1] <= green && green <= searchColor.val[1] + 50) &&
                    (searchColor.val[2] <= red && red <= searchColor.val[2] + 50)) {
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
