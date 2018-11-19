#include "stdafx.h"
#include "NxpCarInterface.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NxpCarInterface w;
    w.show();
    return a.exec();
}
