//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_QPIXMAPTOMATCONVERTER_H
#define BETBOOMTESTTASK_QPIXMAPTOMATCONVERTER_H

#include "IQPixMapToMatConverter.h"
class QPixMapToMatConverter: public IQPixMapToMatConverter{
public:

private:
    cv::Mat convent(QPixmap map) override;

};


#endif //BETBOOMTESTTASK_QPIXMAPTOMATCONVERTER_H
