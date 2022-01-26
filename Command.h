#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <vector>
#include "Result.h"

namespace CLI
{
    class Command  
    {
    public:
        Command();
        Command(const Command& copy);                 // конструктор копирования
        Command& operator=(const Command& copy);      // оператор копирования
        Command(const Command&& copy);                // конструктор перемещения
        Command& operator=(const Command&& copy);     // оператор перемещения
        virtual ~Command();                          // деструктор

        virtual Result exec(std::vector<std::string>) = 0;
        virtual bool matches(std::string) = 0;
    };
}

#endif /* COMMAND_H_ */