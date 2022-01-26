#ifndef COMMANDCONCAT_H_
#define COMMANDCONCAT_H_

#include <string>
#include <vector>
#include "Command.h"
#include "Result.h"

namespace CLI
{
    class CommandConcat: public Command 
    {
    protected:
        inline static const std::string command_concat{"concat"};
    public:
        CommandConcat();
        virtual ~CommandConcat();                        // деструктор
        virtual Result exec(std::vector<std::string>) override;
        virtual bool matches(std::string) override;
    };
}

#endif /* COMMANDCONCAT_H_ */
