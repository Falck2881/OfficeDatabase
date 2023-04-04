#include "ProductTables.h"
#include "FunctionsDataBase.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>
#include <QHeaderView>

QTableView* ProductTables::createTable(const QString &nameTable)
{
    QTableView* productTable{prepareTableView()};
    productTable->setModel(createSqlModelWithData(nameTable));
    productTable->setColumnWidth(1,500);
    return productTable;
}

QSqlTableModel* ProductTables::createSqlModelWithData(const QString &nameTable)
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


QTableView* ProductTables::prepareTableView() const
{
    QTableView* table = new QTableView;
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->horizontalHeader()->setStretchLastSection(true);
    table->verticalHeader()->setStretchLastSection(true);
    return table;
}
