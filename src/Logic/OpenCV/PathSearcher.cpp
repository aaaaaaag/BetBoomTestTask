//
// Created by denis on 17.07.2021.
//

#include "Logic/OpenCV/PathSearcher.h"
#include <utility>
#include "Logic/Exception.h"
#include "cmath"

PathSearcher::PathSearcher(std::shared_ptr<IOpenCVWrapper> wrapper, const cv::Vec3b& backgroundColor):
m_wrapper(std::move(wrapper)),
m_backgroundColor(backgroundColor)
{
}

void PathSearcher::updateWrapper(std::shared_ptr<IOpenCVWrapper> wrapper) {
    m_wrapper = std::move(wrapper);
}

int PathSearcher::GetNearestPath(QPoint start, QPoint end) {
    std::vector<QPoint> v_path;
    v_path.push_back(start);

    m_wrapper->createMatCopy();
    GetPathRec(start, end, v_path);
    m_wrapper->setMatCopy();

    if (m_vPaths.empty())
        throw FailFindRoadException("Road not found");

    size_t minLen = m_vPaths[0].size();
    for (const auto& path: m_vPaths)
    {
        if (path.size() < minLen)
            minLen = path.size();
    }
    m_vPaths.clear();
    return static_cast<int>(minLen);
}

std::vector<QPoint> PathSearcher::getNearDots(QPoint dot) {
    std::vector<QPoint> vPoints;
    vPoints.emplace_back(dot.x() - 1, dot.y());
    vPoints.emplace_back(dot.x() + 1, dot.y());
    vPoints.emplace_back(dot.x(), dot.y() - 1);
    vPoints.emplace_back(dot.x(), dot.y() + 1);
    return vPoints;
}

bool PathSearcher::isWhite(const cv::Vec3b& color)
{
    uint blue = color.val[0];
    uint green = color.val[1];
    uint red = color.val[2];

    if (blue == m_backgroundColor.val[0] &&
        green == m_backgroundColor.val[1] &&
        red == m_backgroundColor.val[2])
        return true;
    return false;

}

void PathSearcher::GetPathRec(QPoint start, QPoint end, std::vector<QPoint> curPath) {
    if (m_vPaths.size() > 1000)
        return;
    for (auto dot: getNearDots(start))
    {
        if (std::find(curPath.begin(), curPath.end(), dot) != curPath.end())
            continue;
        if (isWhite(m_wrapper->getMatPix(dot.x(), dot.y())))
            continue;
        m_wrapper->setMatPix(dot.x(), dot.y(), m_backgroundColor);

        auto copyPath = curPath;
        copyPath.push_back(dot);
        if (dot == end)
            m_vPaths.push_back(curPath);
        else
            GetPathRec(dot, end, copyPath);
    }
}






