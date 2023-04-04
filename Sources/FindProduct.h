#ifndef FINDPRODUCT_H
#define FINDPRODUCT_H

#include "Find.h"

class QTabWidget;
class QTableView;

class FindProduct: public Find
{
    Q_OBJECT

    public:
        FindProduct(QTabWidget* const tabWidget);
    public slots:
        void saveNameProduct(const QString& name);
        void execute() override;
    private:
        bool isExistProductTables() const;
        void searchOfRecord(const QString& nameProduct);
        QTableView* getProductTable() const;
    private:
        QTabWidget* const tabWidget;
        QString nameProduct;
};

#endif // FINDPRODUCT_H
