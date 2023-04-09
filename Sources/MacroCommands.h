#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include <QList>
#include <memory>
#include <QString>


class MacroCommands: public Command
{
    Q_OBJECT

    public:
        MacroCommands() = default;
        void append(std::shared_ptr<Command> command);
    public slots:
        void execute(const QString& nameCompany) override;
    private:
        QList<std::shared_ptr<Command>> allCommands;
};

#endif // MACROCOMMAND_H
