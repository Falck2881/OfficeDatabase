#include "MainWindow.h"
#include <QFile>
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>

static void createConnectWithDataBase();

int main(int argc, char *argv[])
{
    QFile file(":/Medize.qss");
    if(!file.open(QIODevice::ReadOnly))
        qDebug("Warning: The file Medize.qss no find");
    QApplication app(argc, argv);
    app.setStyleSheet(file.readAll());

    createConnectWithDataBase();

    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}

static void createConnectWithDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","db");
    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};"
                       "FIL={MS Access};DBQ=C:/MyProgectQt/OfficeDatabase/DB/DBManufacturer.accdb");
}
