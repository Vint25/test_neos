#include "CommandConcat.h"
#include "Utils.h"

namespace CLI
{
    CommandConcat::CommandConcat()
    {
        
    }
    
    CommandConcat::~CommandConcat()
    {
        
    }

    Result CommandConcat::exec(std::vector<std::string> expressions)
    {
        if (expressions.size()>2)                                               //смотрим чтобы параметров было больше двух, сама команда вычитания и два аргумента  
        {
            std::string command=Utils::StringUtils::trim(Utils::StringUtils::to_lower(expressions[0]));

            if (command==command_concat)
            {
                std::string result="";
                for (int i=1;i<expressions.size();i++)
                {
                    result+=expressions[i];                                         // вычисляем результат
                }

                return Result(true, result);                                        // возвращаем результат
            }
        }
        else
        {
            return Result(false, "command concat, not enough parameters");         // возвращаем ошибку
        }
        return Result(false, "wrong command");
    }
    
    bool CommandConcat::matches(std::string command)
    {
        if (command==command_concat)
            return true;
        else
            return false;
    }
}

