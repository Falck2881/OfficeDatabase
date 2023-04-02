#include "WindowContacts.h"
#include "./ui_WindowContacts.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QSqlQuery>

WindowContacts::WindowContacts(QWidget *parent):
    ui(new Ui::contactWindow)
{
    ui->setupUi(this);
}

void WindowContacts::setContacts(const std::pair<QPixmap, QString> &attributes)
{
   QSqlDatabase dBCompany = QSqlDatabase::database("db");
   if(dBCompany.open()){
       qDebug() << "Success open data base DBManufacturer.accdb";
       changeWindowOfContants(attributes);
   }
   else qDebug() << dBCompany.lastError().text();

}

void WindowContacts::changeWindowOfContants(const std::pair<QPixmap, QString> &attributes)
{
    if(QSqlDatabase::database("db").isOpen()){
        changeLogoCompany(attributes.first);
        changeDescriptionAtCompany(attributes.second);
        changeTitleCompany(attributes.second);
        changeCummonInfo(attributes.second);
        changeCEOInfo(attributes.second);
        changeManagersInfo(attributes.second);
        changeRequisitesInfo(attributes.second);
    }
}

void WindowContacts::changeLogoCompany(const QPixmap& logo)
{
    ui->logoCompany->setPixmap(logo);
}

void WindowContacts::changeDescriptionAtCompany(const QString& id)
{
    const QString select{"SELECT Description FROM Manufactures WHERE ID = %1"};
    QSqlQuery query(select.arg(id), QSqlDatabase::database("db"));
    query.next();
    ui->textEdit->setText(query.value(0).toString());
}

void WindowContacts::changeTitleCompany(const QString& id)
{
    const QString select{"SELECT Name_Company FROM Manufactures WHERE ID = %1"};
    QSqlQuery query(select.arg(id),QSqlDatabase::database("db"));
    query.next();

    QTableWidgetItem* item{new QTableWidgetItem(query.value(0).toString())};
    item->setFont(QFont("Segoe UI", 12, QFont::Bold));
    ui->generalTable->setHorizontalHeaderItem(0,item);
}

void WindowContacts::changeCummonInfo(const QString& id)
{
    const QString select{"SELECT ID, Number_Phone, Addres, EMail, Work_Schedule,"
                         "Time_Work, Weekend FROM Manufactures WHERE ID = %1"};
    QSqlQuery query(select.arg(id),QSqlDatabase::database("db"));
    QSqlRecord record{query.record()};
    query.next();

    for(qint32 index{0}; index < record.count(); ++index)
    {
        auto value{query.value(record.fieldName(index))};
        QTableWidgetItem* item{new QTableWidgetItem(value.toString())};
        ui->generalTable->setItem(index,0,item);
    }
}

void WindowContacts::changeCEOInfo(const QString& id)
{
    const QString select{"SELECT ID, FIO, Number_Phone FROM GeneralManager WHERE ID = %1"};
    QSqlQuery query(select.arg(id),QSqlDatabase::database("db"));
    QSqlRecord record{query.record()};
    query.next();

    for(qint32 index{0}; index < record.count(); ++index)
    {
        auto value{query.value(record.fieldName(index))};
        QString str{value.toString()};
        QTableWidgetItem* item{new QTableWidgetItem(str)};
        ui->ceoTable->setItem(index,0,item);
    }
}

void WindowContacts::changeManagersInfo(const QString& id)
{
    const QString select{"SELECT ID, FIO, Number_Phone FROM MainManagerAtSales WHERE ID = %1"};
    QSqlQuery query(select.arg(id),QSqlDatabase::database("db"));
    QSqlRecord record{query.record()};
    query.next();

    for(qint32 index{0}; index < record.count(); ++index)
    {
        auto value{query.value(record.fieldName(index))};
        QTableWidgetItem* item{new QTableWidgetItem(value.toString())};
        ui->managersTable->setItem(index,0,item);
    }
}

void WindowContacts::changeRequisitesInfo(const QString& id)
{
    const QString select{"SELECT ID, Legal_Name, Legal_Address, Physical_Address,"
                         "INN, OGRNIP, Paymant_Account, Correspondent_Account,"
                         "BIK, Bank FROM Requisites WHERE ID = %1"};
    QSqlQuery query(select.arg(id),QSqlDatabase::database("db"));
    QSqlRecord record{query.record()};
    query.next();

    for(qint32 index{0}; index < record.count(); ++index)
    {
        auto value{query.value(record.fieldName(index))};
        QTableWidgetItem* item{new QTableWidgetItem(value.toString())};
        ui->requisitesTable->setItem(index,0,item);
    }
}

WindowContacts::~WindowContacts()
{
    delete ui;
}

