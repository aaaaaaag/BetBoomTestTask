//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_MATHANDLER_H
#define BETBOOMTESTTASK_MATHANDLER_H

#include "IMatHandler.h"
#include "IOpenCVWrapper.h"
#include "utility"
#include "IPathSearcher.h"
class MatHandler: public IMatHandler{
public:

    explicit MatHandler(std::shared_ptr<IOpenCVWrapper> wrapper, std::shared_ptr<IPathSearcher> pathSearcher);

    void SetStartDot(QPoint dot) override;

    void SetEndDot(QPoint dot) override;

    int GetResultPix() override;

    int GetResultMM() override;

private:

    QPoint m_startDot;
    QPoint m_endDot;
    bool m_isStartSet = false;
    bool m_isEndSet = false;
    std::shared_ptr<IOpenCVWrapper> m_pWrapper;
    std::shared_ptr<IPathSearcher> m_pPathSearcher;
};


#endif //BETBOOMTESTTASK_MATHANDLER_H
