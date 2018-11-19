#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NxpCarInterface.h"

class NxpCarInterface : public QMainWindow
{
    Q_OBJECT

public:
    NxpCarInterface(QWidget *parent = Q_NULLPTR);

private:
    Ui::NxpCarInterfaceClass ui;
};
