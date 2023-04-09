#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QTableView>
#include <QSqlTableModel>

class TableModel
{
    public:
        virtual ~TableModel() = default;
        QSqlTableModel* createModel(const QString& nameTable);
    private:
        QSqlTableModel* createSqlModelWithData(const QString &nameTable);
    protected:
        virtual QString getNameTableFromDataBase(const QString& nameTable) = 0;
        TableModel() = default;
};

#endif // TABLEMODEL_H
