#include "FunctionsDataBase.h"
#include <QSqlDatabase>

void createConnectWithDataBase(const QString& nameConnect)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", nameConnect);
    db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};"
                       "FIL={MS Access};DBQ=C:/MyProgectQt/OfficeDatabase/DB/DBManufacturer.accdb");
}
