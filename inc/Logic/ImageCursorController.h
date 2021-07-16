//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
#define BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H

#include "IImageCursorController.h"

enum class mouseDoState
{
    none,
    setStartDot,
    setEndDot,
};


class ImageCursorController: public IImageCursorController{
public:

    explicit ImageCursorController(QLabel *label);

protected:
    QPointF getMousePos(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *ev) override;

public slots:

    void setStartDot();
    void setEndDot();

signals:

    void dotSet();

private:

    mouseDoState m_state = mouseDoState::none;
    QLabel *m_label;

};


#endif //BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
