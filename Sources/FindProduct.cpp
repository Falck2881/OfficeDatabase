#include "FindProduct.h"
#include <QTabWidget>
#include <QTableView>


FindProduct::FindProduct(QTabWidget* const tabWidget):
    tabWidget(tabWidget)
{
}

void FindProduct::saveNameProduct(const QString& name)
{
    nameProduct = name;
}

void FindProduct::execute()
{
    if(isExistProductTables())
        searchOfRecord(nameProduct);
}

bool FindProduct::isExistProductTables() const
{
    return tabWidget->count() != 1;
}

void FindProduct::searchOfRecord(const QString &nameProduct)
{
    QTableView* productTable{getProductTable()};
    productTable->keyboardSearch(nameProduct);
}

QTableView* FindProduct::getProductTable() const
{
    return qobject_cast<QTableView*>(tabWidget->currentWidget());
}
