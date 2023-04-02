#ifndef IDENTIFYCOMPANY_H
#define IDENTIFYCOMPANY_H

#include "Command.h"
#include <QList>
#include <memory>
#include <QString>


class IdentifyCompany: public Command
{
    Q_OBJECT

    public:
        IdentifyCompany() = default;
        void append(std::unique_ptr<Command> command);
    public slots:
        void execute(const QString& nameCompany) override;
    private:
        QList<std::shared_ptr<Command>> allCommands;
};

#endif // IDENTIFYCONTACTS_H
