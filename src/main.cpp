#include <iostream>
#include <QApplication>
#include "fssapp.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FssApp fss;
    fss.show();
    return app.exec();
}
