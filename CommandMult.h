#ifndef COMMANDMULT_H_
#define COMMANDMULT_H_

#include <string>
#include <vector>
#include "Command.h"
#include "Result.h"

namespace CLI
{
    class CommandMult: public Command 
    {
    protected:
        inline static const std::string command_mult{"mult"};
    public:
        CommandMult();
        virtual ~CommandMult();                        // деструктор
        virtual Result exec(std::vector<std::string>) override;
        virtual bool matches(std::string) override;
    };
}

#endif /* COMMANDMULT_H_ */
