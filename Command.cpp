
#include "Command.h"

namespace CLI
{
    Command::Command() 
    {
    }

    Command::Command(const Command& orig) 
    {
    }

    Command& Command::operator=(const Command& copy)
    {
        return *this;
    }

    Command::Command(const Command&& orig) 
    {
    }

    Command& Command::operator=(const Command&& copy)
    {
        return *this;
    }

    Command::~Command() 
    {
    }
    
}



