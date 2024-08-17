#include "../view/inc/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug() << "Pointer: " << &w << w.size();
    return a.exec();

}
