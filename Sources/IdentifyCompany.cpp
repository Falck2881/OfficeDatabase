#include "IdentifyCompany.h"
#include "WindowContacts.h"

void IdentifyCompany::append(std::shared_ptr<Identify> command)
{
    allCommands.push_back(std::move(command));
}

void IdentifyCompany::execute(const QString& nameCompany)
{
    for(auto command: allCommands)
        command->execute(nameCompany);
}

