#ifndef FINDINTOTABLE_H
#define FINDINTOTABLE_H

#include "FindProduct.h"

class QTableView;

class FindIntoTable: public FindProduct
{
    Q_OBJECT

    public:
        FindIntoTable(QTableView* const tableView);
        void execute() override;
    private:
        QTableView* const tableView;
};

#endif // FINDINTOTABLE_H
