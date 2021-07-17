//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IIMAGECURSORCONTROLLER_H
#define BETBOOMTESTTASK_IIMAGECURSORCONTROLLER_H

#include "QMouseEvent"
#include "QLabel"

class IImageCursorController: public QLabel{
protected:

    virtual QPoint getMousePos(QMouseEvent *event) = 0;

};


#endif //BETBOOMTESTTASK_IIMAGECURSORCONTROLLER_H
