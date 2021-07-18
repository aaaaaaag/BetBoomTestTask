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

    explicit PathSearcher(std::shared_ptr<IOpenCVWrapper> wrapper, const cv::Vec3b& backgroundColor);

    int GetNearestPath(QPoint start, QPoint end) override;
    void updateWrapper(std::shared_ptr<IOpenCVWrapper> wrapper);

private:
    bool isWhite(const cv::Vec3b& color);
    void GetPathRec(QPoint start, QPoint end, std::vector<QPoint> curPath);
    static std::vector<QPoint> getNearDots(QPoint dot);

    std::vector<std::vector<QPoint>> m_vPaths;
    cv::Vec3b m_backgroundColor;
    std::shared_ptr<IOpenCVWrapper> m_wrapper;
};


#endif //BETBOOMTESTTASK_PATHSEARCHER_H
