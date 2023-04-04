#ifndef IDENTIFYPRODUCT_H
#define IDENTIFYPRODUCT_H

#include "Identify.h"

class QTabWidget;
class ProductTables;

class IdentifyProduct: public Identify
{
    Q_OBJECT
    public:
        IdentifyProduct(QTabWidget* const productTables);
    public slots:
        void execute(const QString &idCompany) override;
        void addProductsTable(const QString& nameTable);
    private:
        ProductTables* createProductTable(const QString& nameTable);
        ProductTables* prepareProductTable();
    private:
        QTabWidget* const tabWidget;
        ProductTables* productTable;

};

#endif // IDENTIFYPRODUCT_H
