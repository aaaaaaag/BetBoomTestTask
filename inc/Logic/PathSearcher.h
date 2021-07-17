//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_PATHSEARCHER_H
#define BETBOOMTESTTASK_PATHSEARCHER_H

#include <QPoint>
#include "IPathSearcher.h"
#include "IOpenCVWrapper.h"
class PathSearcher: public IPathSearcher {
public:

    explicit PathSearcher(std::shared_ptr<IOpenCVWrapper> wrapper);
    void updateWrapper(std::shared_ptr<IOpenCVWrapper> wrapper);

    int GetNearestPath(QPoint start, QPoint end) override;

private:

    void GetPathRec(QPoint start, QPoint end, std::vector<QPoint> curPath);

    static std::vector<QPoint> getNearDots(QPoint dot);

    bool isColorNeed(const cv::Vec3b& color);

    std::vector<std::vector<QPoint>> m_vPaths;

    std::shared_ptr<IOpenCVWrapper> m_wrapper;
    cv::Vec3b m_lowColor;
    cv::Vec3b m_highColor;
};


#endif //BETBOOMTESTTASK_PATHSEARCHER_H
