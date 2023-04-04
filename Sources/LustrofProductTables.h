#ifndef LUSTROFPRODUCTTABLES_H
#define LUSTROFPRODUCTTABLES_H

#include "ProductTables.h"

class LustrofProductTables: public ProductTables
{
    public:
        LustrofProductTables() = default;
    private:
        QString getNameTableFromDataBase(const QString& nameTable) override;
};
#endif // LUSTROFPRODUCTTABLES_H
