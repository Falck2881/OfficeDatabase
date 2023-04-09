#ifndef ADDCONTACTS_H
#define ADDCONTACTS_H

#include "Command.h"
#include <utility>
#include <QPixmap>
#include <QString>

class WindowContacts;

class AddContacts: public Command
{
    Q_OBJECT

    public:
        AddContacts(WindowContacts* winContacts);
    public slots:
        void execute(const QString &nameCompany) override;
        std::pair<QPixmap,QString> getAttributesCompany(const QString &nameCompany) const;
    private:
        WindowContacts* const winContacts;
};

#endif // ADDCONTACTS_H
