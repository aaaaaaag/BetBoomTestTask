//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_LABELIMAGELOADER_H
#define BETBOOMTESTTASK_LABELIMAGELOADER_H

#include "ILabelImageLoader.h"
class LabelImageLoader: public ILabelImageLoader{
public:

    IImageLabel *loadImageToLabel(std::string path) override;
};


#endif //BETBOOMTESTTASK_LABELIMAGELOADER_H
