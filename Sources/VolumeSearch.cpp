#include "VolumeSearch.h"

void VolumeSearch::append(std::shared_ptr<Find> command)
{
    commands.push_back(command);
}

void VolumeSearch::execute()
{
    for(auto command: commands)
        command->execute();
}
