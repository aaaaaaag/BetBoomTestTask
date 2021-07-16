//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IOPENCVWRAPPER_H
#define BETBOOMTESTTASK_IOPENCVWRAPPER_H

#include "opencv2/opencv.hpp"
#include "string"

class IOpenCVWrapper
{
public:
    virtual ~IOpenCVWrapper() = default;
    virtual void loadImage(std::string path) = 0;
    virtual cv::Vec3b getMatPix(int x, int y) = 0;
    virtual void setMatPix(int x, int y, cv::Vec3b pix) = 0;


};

#endif //BETBOOMTESTTASK_IOPENCVWRAPPER_H
