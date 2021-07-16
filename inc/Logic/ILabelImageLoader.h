//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_ILABELIMAGELOADER_H
#define BETBOOMTESTTASK_ILABELIMAGELOADER_H

#include "QLabel"
#include "string"
class ILabelImageLoader {
public:
    virtual ~ILabelImageLoader() = default;
    virtual QLabel* loadImageToLabel(std::string path) = 0;
};


#endif //BETBOOMTESTTASK_ILABELIMAGELOADER_H
