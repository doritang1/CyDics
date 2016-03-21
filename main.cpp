#include "cydicmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CyDicMain w;
    w.show();

    return a.exec();
}
