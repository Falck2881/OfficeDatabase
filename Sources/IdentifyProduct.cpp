#include "IdentifyProduct.h"
#include "LustrofProductTables.h"
#include "BraubergProductTables.h"
#include <QTabWidget>

IdentifyProduct::IdentifyProduct(QTabWidget* const tabWidget):
    tabWidget(tabWidget), productTable(nullptr)
{

}

void IdentifyProduct::execute(const QString &nameProvider)
{
    productTable = prepareProductTable();
    productTable = createProductTable(nameProvider);
}

ProductTables* IdentifyProduct::prepareProductTable()
{
    if(productTable != nullptr){
        delete productTable;
        productTable = nullptr;
    }
    return productTable;
}

ProductTables* IdentifyProduct::createProductTable(const QString &nameProvider)
{
    if(nameProvider == "Lustrof")
        return new LustrofProductTables;
    else if(nameProvider == "Brauberg")
        return new BraubergProductTables;
}

void IdentifyProduct::addProductsTable(const QString& nameTable)
{
    if(nameTable != "Выбрать тип товаров"){
        tabWidget->addTab(productTable->createTable(nameTable),nameTable);
    }
}
