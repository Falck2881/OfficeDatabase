#ifndef FUNCTIONSDATABASE_H
#define FUNCTIONSDATABASE_H

#include <QString>
#include <QSqlDatabase>

static void createConnectWithDataBase(const QString& nameConnect)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", nameConnect);
    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};"
                       "FIL={MS Access};DBQ=./DBManufacturer.accdb");
}


#endif // FUNCTIONSDATABASE_H
