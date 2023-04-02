#include "IdentifyCompany.h"
#include "WindowContacts.h"

void IdentifyCompany::append(std::unique_ptr<Command> command)
{
    allCommands.push_back(std::move(command));
}

void IdentifyCompany::execute(const QString& nameCompany)
{
    for(auto command: allCommands)
        command->execute(nameCompany);
}

