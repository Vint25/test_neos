#ifndef COMMANDADD_H_
#define COMMANDADD_H_

#include <string>
#include <vector>
#include "Command.h"
#include "Result.h"

namespace CLI
{
    class CommandAdd: public Command 
    {
    protected:
        inline static const std::string command_add{"add"};
    public:
        CommandAdd();
        virtual ~CommandAdd();                          // деструктор
        virtual Result exec(std::vector<std::string>) override;
        virtual bool matches(std::string) override;
    };
}

#endif /* COMMANDADD_H_ */