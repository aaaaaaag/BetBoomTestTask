//
// Created by denis on 17.07.2021.
//

#ifndef BETBOOMTESTTASK_WARNINGTHROWER_H
#define BETBOOMTESTTASK_WARNINGTHROWER_H

#include "IWarningThrower.h"

//QMessageBox::critical(this, "Ошибка ", "Неверный ввод координат.", QMessageBox::Ok);
class WarningThrower {
public:

    static void ShowWarning(Exception *ex);

};


#endif //BETBOOMTESTTASK_WARNINGTHROWER_H
