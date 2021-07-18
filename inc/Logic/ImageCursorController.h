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

enum class mouseDoState
{
    none,
    setStartDot,
    setEndDot,
};


class ImageCursorController: public ImageLabel{

    Q_OBJECT

public slots:

    void setStartDot();
    void setEndDot();
    void res();
public:

    explicit ImageCursorController(IConnectMediator* mediator, std::shared_ptr<IMatHandler> matHandler);

protected:
    static QPoint getMousePos(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *ev) override;

private:
    std::shared_ptr<IMatHandler> m_pMatHandler;
    mouseDoState m_state = mouseDoState::none;
    QLabel *m_label{};

};


#endif //BETBOOMTESTTASK_IMAGECURSORCONTROLLER_H
