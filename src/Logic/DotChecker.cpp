//
// Created by denis on 17.07.2021.
//

#include "Logic/DotChecker.h"

bool DotChecker::IsDotCorrect(const std::shared_ptr<IOpenCVWrapper>& wrapper, QPoint point, int rad) {
    auto x = point.x();
    auto y = point.y();
    cv::Vec3b searchColor = {255, 0, 0};
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
                    (searchColor.val[2] <= red && red <= searchColor.val[2])) {
                    isFind = true;
                }
            }
        }
    }
    return isFind;
}
