#include "AddContacts.h"
#include "WindowContacts.h"

AddContacts::AddContacts(WindowContacts* const winContacts):
    winContacts(winContacts)
{
}

void AddContacts::execute(const QString& nameCompany)
{
    auto attributes{getAttributesCompany(nameCompany)};
    winContacts->setContacts(attributes);
}

std::pair<QPixmap, QString> AddContacts::getAttributesCompany(const QString &nameCompany) const
{
    if(nameCompany == "Lustrof")
        return std::make_pair<QPixmap,QString>(QPixmap(":/lustrofLogo.png"),QString("7318602"));
    else if(nameCompany == "Brauberg")
        return std::make_pair<QPixmap,QString>(QPixmap(":/braubergLogo.png"),QString("7385144"));
    else
        return std::make_pair<QPixmap,QString>(QPixmap("*"),QString("not found"));;
}
