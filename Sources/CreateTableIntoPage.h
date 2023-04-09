#ifndef CREATETABLEINTOPAGE_H
#define CREATETABLEINTOPAGE_H

#include "AddTable.h"

class QTabWidget;

namespace Create
{
    class TableIntoPage: public AddTable
    {
        public:
            TableIntoPage(QTabWidget* const tabWgd);
        private:
            QTableView* prepareTableView() const;
            void createTable(const QString &nameTable) override;
            QTabWidget* const tabWgd;
    };
}
#endif // CREATETABLEINTOPAGE_H
