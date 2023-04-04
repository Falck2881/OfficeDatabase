#ifndef BRAUBERGPRODUCTTABLES_H
#define BRAUBERGPRODUCTTABLES_H

#include "ProductTables.h"

class BraubergProductTables: public ProductTables
{
    public:
        BraubergProductTables() = default;
    private:
        QString getNameTableFromDataBase(const QString& nameTable) override;
};

#endif // BRAUBERGPRODUCTTABLES_H
