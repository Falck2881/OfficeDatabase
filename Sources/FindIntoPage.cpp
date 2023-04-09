#include "FindIntoPage.h"
#include <QTabWidget>
#include <QTableView>

FindIntoPage::FindIntoPage(QTabWidget* const tabWidget):tabWidget(tabWidget)
{
}

void FindIntoPage::execute()
{
    if(isExistProductTables())
        searchOfRecord(nameProduct);
}

bool FindIntoPage::isExistProductTables() const
{
    return tabWidget->count() != 1;
}

void FindIntoPage::searchOfRecord(const QString &nameProduct)
{
    QTableView* productTable{getProductTable()};
    productTable->keyboardSearch(nameProduct);
}

QTableView* FindIntoPage::getProductTable() const
{
    return qobject_cast<QTableView*>(tabWidget->currentWidget());
}
