#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <memory>
#include "Command.h"
#include "Result.h"

namespace CLI
{
    class Parser
    {
    public:

        Parser();
        Parser(const Parser& copy)=delete;  // запрещаем всекопирование
        Parser& operator=(const Parser& copy)=delete;
        Parser(const Parser&& copy)=delete;
        Parser& operator=(const Parser&& copy)=delete;
        Result run(std::string command);
        virtual ~Parser();
        bool isRun();  // Возвращает флаг, для проверки работы. команда quit утановит флаг в false

    protected:
        inline static const std::string command_quit{"quit"};
        std::vector<std::shared_ptr<Command>> workers;
        bool running=true;
        Result exec_command(std::vector<std::string> expressions);       // метод выполнения команды
    };
}

#endif /* PARSER_H_ */