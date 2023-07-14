#ifndef FUNCTIONSDATABASE_H
#define FUNCTIONSDATABASE_H

#include <QString>
#include <QSqlDatabase>
#include <QCoreApplication>

static void createConnectWithDataBase(const QString& nameConnect)
{
    QString path = QCoreApplication::applicationDirPath() + "/DBManufacturer.accdb";
    QString dbName = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};"
                     "FIL={MS Access};DBQ=" + path;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", nameConnect);
    db.setDatabaseName(dbName);
}


#endif // FUNCTIONSDATABASE_H
