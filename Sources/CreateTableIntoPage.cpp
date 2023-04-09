#include "CreateTableIntoPage.h"
#include <QTabWidget>
#include <QTableView>
#include <QHeaderView>

Create::TableIntoPage::TableIntoPage(QTabWidget* const tabWgd):
    tabWgd(tabWgd)
{
}

void Create::TableIntoPage::createTable(const QString &nameTable)
{
    QTableView* table{prepareTableView()};
    table->setModel(model->createModel(nameTable));
    table->setColumnWidth(1,500);
    tabWgd->addTab(table,nameTable);
}

QTableView* Create::TableIntoPage::prepareTableView() const
{
    QTableView* table = new QTableView;
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->horizontalHeader()->setStretchLastSection(true);
    table->verticalHeader()->setStretchLastSection(true);
    return table;
}
