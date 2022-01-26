#include "CommandSub.h"
#include "Utils.h"

namespace CLI
{
    CommandSub::CommandSub()
    {
        
    }
    
    CommandSub::~CommandSub()
    {
        
    }

    Result CommandSub::exec(std::vector<std::string> expressions)
    {
        if (expressions.size()>2)                                               //смотрим чтобы параметров было больше двух, сама команда вычитания и два аргумента  
        {
            std::string command=Utils::StringUtils::trim(Utils::StringUtils::to_lower(expressions[0]));

            if (command==command_sub)
            {
                int result=0;

                if (!Utils::StringUtils::int_parse(expressions[1], result))         // преобразуем строку в int
                    return Result(false, "wrong argument \""+expressions[1]+"\"");

                for (int i=2;i<expressions.size();i++)
                {
                    int val=0;
                    if (!Utils::StringUtils::int_parse(expressions[i], val))        // преобразуем строку в int
                        return Result(false, "wrong argument \""+expressions[i]+"\"");

                    result=result-val;                                              // вычисляем результат
                }
                
                return Result(true, std::to_string(result));                        // возвращаем результат
            }
        }
        else
        {
            return Result(false, "command sub, not enough parameters");         // возвращаем ошибку
        }
        return Result(false, "wrong command");
    }
    
    bool CommandSub::matches(std::string command)
    {
        if (command==command_sub)
            return true;
        else
            return false;
    }
}

