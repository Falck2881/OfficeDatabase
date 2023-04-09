#include "MacroCommands.h"
#include "WindowContacts.h"

void MacroCommands::append(std::shared_ptr<Command> command)
{
    allCommands.push_back(std::move(command));
}

void MacroCommands::execute(const QString& nameCompany)
{
    for(auto command: allCommands)
        command->execute(nameCompany);
}

