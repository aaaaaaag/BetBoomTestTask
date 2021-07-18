//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_OPENCVWRAPPER_H
#define BETBOOMTESTTASK_OPENCVWRAPPER_H

#include "IOpenCVWrapper.h"

class OpenCVWrapper: public IOpenCVWrapper{
public:

    void loadImage(std::string path) override;

    cv::Vec3b getMatPix(int x, int y) override;

    void setMatPix(int x, int y, cv::Vec3b pix) override;

    cv::Mat getMat() override;

    void createMatCopy() override;

    void setMatCopy() override;

private:
    cv::Mat m_imageMatrixCopy;
    cv::Mat m_imageMatrix;

};


#endif //BETBOOMTESTTASK_OPENCVWRAPPER_H
