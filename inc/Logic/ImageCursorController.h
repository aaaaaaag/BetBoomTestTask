//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
#define BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H

#include <memory>
#include "IImageCursorController.h"
#include "IMatHandler.h"
#include "utility"
#include "Qt/ImageLabel.h"
#include "Qt/IConnectMediator.h"
#include "QMouseEvent"


class ImageCursorController: public IImageCursorController{
public:

    explicit ImageCursorController(std::shared_ptr<IMatHandler> matHandler, QSize origImageSize);

    void setState(mouseDoState state) override;

protected:
    QPoint getMousePos(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *ev) override;

private:
    std::shared_ptr<IMatHandler> m_pMatHandler;
};


#endif //BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
