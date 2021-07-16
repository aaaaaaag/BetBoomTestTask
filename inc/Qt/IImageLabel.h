//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IIMAGELABEL_H
#define BETBOOMTESTTASK_IIMAGELABEL_H

#include "QLabel"

class IImageLabel: public QLabel{
public:

    ~IImageLabel() override = default;

    virtual const QPixmap* getPixMap() = 0;

signals:

    void ImageChanged();

};


#endif //BETBOOMTESTTASK_IIMAGELABEL_H
