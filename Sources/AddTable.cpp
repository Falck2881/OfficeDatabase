#include "AddTable.h"
#include "LustrofTableName.h"
#include "BraubergTableName.h"
#include <QTabWidget>

AddTable::AddTable():model(nullptr)
{
}

void AddTable::prepareTable(const QString &nameCompany)
{
    model = prepareTableModel();
    model = initializeModel(nameCompany);
}

TableModel* AddTable::prepareTableModel()
{
    if(model != nullptr){
        delete model;
        model = nullptr;
    }
    return model;
}

TableModel* AddTable::initializeModel(const QString &nameCompany)
{
    if(nameCompany == "Lustrof")
        return new LustrofTableName;
    else if(nameCompany == "Brauberg")
        return new BraubergTableName;
    else
        return nullptr;
}

void AddTable::execute(const QString& nameTable)
{
    if(nameTable != "Выбрать тип товаров")
        createTable(nameTable);
}
