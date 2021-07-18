//
// Created by denis on 17.07.2021.
//

#include "Qt/WarningThrower.h"
#include "QMessageBox"

void WarningThrower::ShowWarning(Exception *ex) {
    QString str;
    str.append(ex->getError().data());
    QMessageBox::critical(nullptr, "Error", str, QMessageBox::Ok);
    //QMessageBox::critical(this, "Ошибка", ex->getError(), QMessageBox::Ok);
}
