#ifndef ADDTABLE_H
#define ADDTABLE_H

#include "Command.h"
#include "TableModel.h"

class QTabWidget;

class AddTable: public Command
{
    Q_OBJECT
    public:
        virtual ~AddTable() = default;
    public slots:
        void execute(const QString &nameTable) override;
        void prepareTable(const QString& nameCompany);
    private:
        TableModel* initializeModel(const QString& nameTable);
        TableModel* prepareTableModel();
    protected:
        virtual void createTable(const QString& nameTable) = 0;
        AddTable();
        TableModel* model;
};

#endif // ADDTABLE_H
