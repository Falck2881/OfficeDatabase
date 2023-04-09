#include "FindIntoTable.h"
#include <QTableView>

FindIntoTable::FindIntoTable(QTableView* const tableView):
    tableView(tableView)
{
}

void FindIntoTable::execute()
{
    tableView->keyboardSearch(nameProduct);
}
