#ifndef LUSTROFPRODUCTTABLES_H
#define LUSTROFPRODUCTTABLES_H

#include "TableModel.h"

class LustrofTableName: public TableModel
{
    public:
        LustrofTableName() = default;
    private:
        QString getNameTableFromDataBase(const QString& nameTable) override;
};
#endif // LUSTROFPRODUCTTABLES_H
