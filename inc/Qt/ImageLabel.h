//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IMAGELABEL_H
#define BETBOOMTESTTASK_IMAGELABEL_H

#include "IImageLabel.h"

class ImageLabel: public IImageLabel{
public:

    ImageLabel() = default;
    explicit ImageLabel(QSize origImageSize);
    const QPixmap* getPixMap() override;
    void reformSize(QSize size) override;
    QSize getOrigImageSize() override;
protected:

    QSize m_origImageSize = QSize(0, 0);

};


#endif //BETBOOMTESTTASK_IMAGELABEL_H
