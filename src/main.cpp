#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixSize();
    qDebug() << "Pointer: " << &w << w.size() << "\n";
    return a.exec();

}
