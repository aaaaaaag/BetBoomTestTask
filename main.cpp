#include <QApplication>
#include "Qt/MainWidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWidget widget("asd");
    widget.show();

    return QApplication::exec();
}
