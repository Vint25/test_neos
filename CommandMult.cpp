#include "CommandMult.h"
#include "Utils.h"

namespace CLI
{
    CommandMult::CommandMult()
    {
        
    }
    
    CommandMult::~CommandMult()
    {
        
    }

    Result CommandMult::exec(std::vector<std::string> expressions)
    {
        if (expressions.size()>2)                                               //смотрим чтобы параметров было больше двух, сама команда вычитания и два аргумента  
        {
            std::string command=Utils::StringUtils::trim(Utils::StringUtils::to_lower(expressions[0]));

            if (command==command_mult)
            {
                long result=0;

                if (!Utils::StringUtils::int_parse(expressions[1], (int&)result))         // преобразуем строку в int, то, что в параметрах идет long ничего страшного, long для того, чтобы int не переполнился
                    return Result(false, "wrong argument \""+expressions[1]+"\"");

                for (int i=2;i<expressions.size();i++)
                {
                    int val=0;
                    if (!Utils::StringUtils::int_parse(expressions[i], val))        // преобразуем строку в int
                        return Result(false, "wrong argument \""+expressions[i]+"\"");

                    result=result*val;                                              // вычисляем результат

                }
                return Result(true, std::to_string(result));                        // возвращаем результат
            }
        }
        else
        {
            return Result(false, "command mult, not enough parameters");         // возвращаем ошибку
        }
        return Result(false, "wrong command");
    }
    
    bool CommandMult::matches(std::string command)
    {
        if (command==command_mult)
            return true;
        else
            return false;
    }
}

