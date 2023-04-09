#include "TableModel.h"
#include "FunctionsDataBase.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>

QSqlTableModel* TableModel::createModel(const QString &nameTable)
{
    static qint32 count{0};
    const QString nameConnect{nameTable + QString::number(count)};
    ++count;

    createConnectWithDataBase(nameConnect);
    QSqlDatabase dbCompany = QSqlDatabase::database(nameConnect);
    QSqlTableModel* model = nullptr;

    if(dbCompany.open()){
        qDebug() << "Success open data base DBManufacturer.accdb";
        model = new QSqlTableModel(nullptr,dbCompany);
        model->setTable(getNameTableFromDataBase(nameTable));
        model->select();
    }
    else qDebug() << dbCompany.lastError().text();

    return model;
}
