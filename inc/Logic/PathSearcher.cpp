//
// Created by denis on 17.07.2021.
//

#include "PathSearcher.h"
#include <utility>
#include "Logic/Exception.h"
#include "cmath"

PathSearcher::PathSearcher(std::shared_ptr<IOpenCVWrapper> wrapper): m_wrapper(std::move(wrapper)) {
    m_highColor = {0, 0, 0};
    m_lowColor = {200, 200, 200};
}

void PathSearcher::updateWrapper(std::shared_ptr<IOpenCVWrapper> wrapper) {
    m_wrapper = std::move(wrapper);
}

int PathSearcher::GetNearestPath(QPoint start, QPoint end) {
    std::vector<QPoint> v_path;
    v_path.push_back(start);
    GetPathRec(start, end, v_path);
    if (m_vPaths.empty())
        throw FailFindRoadException("Road not found");
    size_t minLen = m_vPaths[0].size();
    for (const auto& path: m_vPaths)
    {
        if (path.size() < minLen)
            minLen = path.size();
    }
    return static_cast<int>(minLen);
}

std::vector<QPoint> PathSearcher::getNearDots(QPoint dot) {
    std::vector<QPoint> vPoints;
    vPoints.emplace_back(dot.x() + 1, dot.y());
    vPoints.emplace_back(dot.x() - 1, dot.y());
    vPoints.emplace_back(dot.x(), dot.y() + 1);
    vPoints.emplace_back(dot.x(), dot.y() - 1);
}

void PathSearcher::GetPathRec(QPoint start, QPoint end, std::vector<QPoint> curPath) {
    auto nearDots = getNearDots(start);
    for (auto dot: nearDots)
    {
        if (std::find(curPath.begin(), curPath.end(), dot) != curPath.end())
            continue;
        if (!isColorNeed(m_wrapper->getMatPix(dot.x(), dot.y())))
            continue;

        auto copyPath = curPath;
        copyPath.push_back(dot);
        if (dot == end)
            m_vPaths.push_back(curPath);
        else
            GetPathRec(dot, end, copyPath);
    }
}

bool PathSearcher::isColorNeed(const cv::Vec3b& color) {
    uint blue = color.val[0];
    uint green = color.val[1];
    uint red = color.val[2];
    if (abs(static_cast<int>(blue - green)) > 30 ||
            abs(static_cast<int>(blue - red)) > 30 ||
            abs(static_cast<int>(red - green)) > 30)
        return false;

    if (m_highColor.val[0] <= blue && blue <= m_lowColor.val[0] &&
            m_highColor.val[1] <= green && green <= m_lowColor.val[1] &&
            m_highColor.val[2] <= red && red <= m_lowColor.val[2])
        return true;
    return false;
}
