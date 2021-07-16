//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IQPIXMAPTOMATCONVERTER_H
#define BETBOOMTESTTASK_IQPIXMAPTOMATCONVERTER_H

#include "opencv2/opencv.hpp"
#include "QPixmap"

class IQPixMapToMatConverter {
public:

    virtual ~IQPixMapToMatConverter() = default;
    virtual cv::Mat convent(QPixmap map) = 0;
};


#endif //BETBOOMTESTTASK_IQPIXMAPTOMATCONVERTER_H
