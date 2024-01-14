#include "FindIntoPage.h"
#include <QTabWidget>
#include <QTableView>

FindIntoPage::FindIntoPage(QTabWidget* const tabWidget):tabWidget(tabWidget)
{
}

void FindIntoPage::execute()
{
    if(isExistProductTables())
        searchOfRecord();
}

bool FindIntoPage::isExistProductTables() const
{
    return tabWidget->count() != 1;
}

void FindIntoPage::searchOfRecord()
{
    QTableView* productTable{getProductTable()};
    productTable->keyboardSearch(nameProduct);
}

QTableView* FindIntoPage::getProductTable() const
{
    return qobject_cast<QTableView*>(tabWidget->currentWidget());
}
