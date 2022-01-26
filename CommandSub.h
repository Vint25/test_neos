#ifndef COMMANDSUB_H_
#define COMMANDSUB_H_

#include <string>
#include <vector>
#include "Command.h"
#include "Result.h"

namespace CLI
{
    class CommandSub: public Command 
    {
    protected:
        inline static const std::string command_sub{"sub"};
    public:
        CommandSub();
        virtual ~CommandSub();                          // деструктор
        virtual Result exec(std::vector<std::string>) override;
        virtual bool matches(std::string) override;
    };
}

#endif /* COMMANDSUB_H_ */
