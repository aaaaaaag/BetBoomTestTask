//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IMAGELABEL_H
#define BETBOOMTESTTASK_IMAGELABEL_H

#include "IImageLabel.h"

class ImageLabel: public IImageLabel{
public:

    const QPixmap* getPixMap() override;

};


#endif //BETBOOMTESTTASK_IMAGELABEL_H
