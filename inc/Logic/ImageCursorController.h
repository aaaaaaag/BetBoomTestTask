//
// Created by denis on 16.07.2021.
//

#ifndef BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
#define BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H

#include <memory>
#include "IImageCursorController.h"
#include "IMatHandler.h"
#include "utility"

enum class mouseDoState
{
    none,
    setStartDot,
    setEndDot,
};


class ImageCursorController: public IImageCursorController{
public:

    explicit ImageCursorController(QLabel *label, std::shared_ptr<IMatHandler> matHandler);

protected:
    QPoint getMousePos(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *ev) override;

public slots:

    void setStartDot();
    void setEndDot();

signals:

    void dotSet();

private:
    std::shared_ptr<IMatHandler> m_pMatHandler;
    mouseDoState m_state = mouseDoState::none;
    QLabel *m_label;

};


#endif //BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
