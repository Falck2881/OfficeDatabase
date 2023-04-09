#ifndef CREATETABLE_H
#define CREATETABLE_H

#include "AddTable.h"

class QTableView;

namespace Create
{
    class ModelIntoTable: public AddTable
    {
        public:
            ModelIntoTable(QTableView* const table);
        private:
            bool isExistTableModel() const;
            void removeModel();
            void createTable(const QString &nameTable) override;
            QTableView* const table;
    };
}
#endif // CREATETABLE_H
