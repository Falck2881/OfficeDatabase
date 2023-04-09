#include "CreateModelIntoTable.h"
#include <QTableView>
#include <QSqlTableModel>

Create::ModelIntoTable::ModelIntoTable(QTableView* const table):
    table(table)
{

}

void Create::ModelIntoTable::createTable(const QString &nameTable)
{
    if(isExistTableModel())
        removeModel();

    table->setModel(model->createModel(nameTable));
    table->setColumnWidth(1,500);
}

bool Create::ModelIntoTable::isExistTableModel() const
{
    return  table->model() != nullptr;
}

void Create::ModelIntoTable::removeModel()
{
    QAbstractItemModel* currentModel{table->model()};
    delete currentModel;
}
