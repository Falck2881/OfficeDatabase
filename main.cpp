#include "MainWindow.h"
#include <QFile>
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QFile file(":/Medize.qss");
    if(!file.open(QIODevice::ReadOnly))
        qDebug("Warning: The file Medize.qss no find");
    QApplication app(argc, argv);
    app.setStyleSheet(file.readAll());

    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
