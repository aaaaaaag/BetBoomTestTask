//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IIMAGECURSORCONTROLLER_H
#define BETBOOMTESTTASK_IIMAGECURSORCONTROLLER_H

#include "QLabel"
#include "Qt/ImageLabel.h"

enum class mouseDoState
{
    none,
    setStartDot,
    setEndDot,
};

class IImageCursorController: public ImageLabel{
public:
    IImageCursorController() {
        m_state = mouseDoState::none;
    }

    ~IImageCursorController() override = default;
    virtual void setState(mouseDoState state) = 0;

protected:

    mouseDoState m_state;

};


#endif //BETBOOMTESTTASK_IIMAGECURSORCONTROLLER_H
