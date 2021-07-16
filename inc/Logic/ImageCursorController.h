//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
#define BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H

#include "IImageCursorController.h"
class ImageCursorController: public IImageCursorController{
public:

    explicit ImageCursorController(QLabel *label);

protected:
    QPointF getMousePos(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *ev) override;

private:

    QLabel *m_label;

};


#endif //BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
