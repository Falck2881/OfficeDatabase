#ifndef IDENTIFYCONTACTS_H
#define IDENTIFYCONTACTS_H

#include "Command.h"
#include <utility>
#include <QPixmap>
#include <QString>

class WindowContacts;

class IdentifyContacts: public Command
{
    Q_OBJECT

    public:
        IdentifyContacts(WindowContacts* winContacts);
    public slots:
        void execute(const QString &nameCompany) override;
        std::pair<QPixmap,QString> getAttributesCompany(const QString &nameCompany) const;
    private:
        WindowContacts* const winContacts;
};

#endif // IDENTIFYCONTACTS_H
