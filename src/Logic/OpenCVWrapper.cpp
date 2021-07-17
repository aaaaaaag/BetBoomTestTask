//
// Created by denis on 16.07.2021.
//

#include "Logic/OpenCVWrapper.h"

void OpenCVWrapper::loadImage(std::string path) {
    m_imageMatrix = cv::imread(path);
}

cv::Vec3b OpenCVWrapper::getMatPix(int x, int y) {
    return m_imageMatrix.at<cv::Vec3b>(x, y);
}

void OpenCVWrapper::setMatPix(int x, int y, cv::Vec3b pix) {
    m_imageMatrix.at<cv::Vec3b>(x, y) = pix;
}
