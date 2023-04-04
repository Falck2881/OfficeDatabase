#ifndef PRODUCTTABLES_H
#define PRODUCTTABLES_H

#include <QTableView>
#include <QSqlTableModel>

class ProductTables
{
    public:
        virtual ~ProductTables() = default;
        QTableView* createTable(const QString& nameTable);
    private:
        QTableView* prepareTableView() const;
        QSqlTableModel* createSqlModelWithData(const QString &nameTable);
    protected:
        virtual QString getNameTableFromDataBase(const QString& nameTable) = 0;
        ProductTables() = default;
};

#endif // PRODUCTTABLES_H
