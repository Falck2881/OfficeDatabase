#ifndef BRAUBERGPRODUCTTABLES_H
#define BRAUBERGPRODUCTTABLES_H

#include "TableModel.h"

class BraubergTableName: public TableModel
{
    public:
        BraubergTableName() = default;
    private:
        QString getNameTableFromDataBase(const QString& nameTable) override;
};

#endif // BRAUBERGPRODUCTTABLES_H
