#ifndef FINDPRODUCT_H
#define FINDPRODUCT_H

#include "Find.h"

class QTableView;

class FindProduct: public Find
{
    Q_OBJECT

    public:
        virtual ~FindProduct() = default;
    public slots:
        void saveNameProduct(const QString& name);
        virtual void execute() = 0;
    protected:
        FindProduct() = default;
        QString nameProduct;
};
#endif // FINDPRODUCT_H
