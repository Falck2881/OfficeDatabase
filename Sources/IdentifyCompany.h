#ifndef IDENTIFYCOMPANY_H
#define IDENTIFYCOMPANY_H

#include "Identify.h"
#include <QList>
#include <memory>
#include <QString>


class IdentifyCompany: public Identify
{
    Q_OBJECT

    public:
        IdentifyCompany() = default;
        void append(std::shared_ptr<Identify> command);
    public slots:
        void execute(const QString& nameCompany) override;
    private:
        QList<std::shared_ptr<Identify>> allCommands;
};

#endif // IDENTIFYCONTACTS_H
