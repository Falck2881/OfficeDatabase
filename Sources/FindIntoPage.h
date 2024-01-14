#ifndef FINDINTOPAGE_H
#define FINDINTOPAGE_H

#include "FindProduct.h"

class QTabWidget;

class FindIntoPage: public FindProduct
{
    Q_OBJECT

    public:
        FindIntoPage(QTabWidget* const tabWidget);
    public slots:
        void execute() override;
    private:
        bool isExistProductTables() const;
        void searchOfRecord();
        QTableView* getProductTable() const;
    private:
        QTabWidget* const tabWidget;
};

#endif // FINDINTOPAGE_H
