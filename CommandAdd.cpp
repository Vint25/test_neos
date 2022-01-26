#include "CommandAdd.h"
#include "Utils.h"

namespace CLI
{
    CommandAdd::CommandAdd()
    {
        
    }
    
    CommandAdd::~CommandAdd()
    {
        
    }

    Result CommandAdd::exec(std::vector<std::string> expressions)
    {
        if (expressions.size()>2)                                               //смотрим чтобы параметров было больше двух, сама команда сложения и два аргумента  
        {
            std::string command=Utils::StringUtils::trim(Utils::StringUtils::to_lower(expressions[0]));

            if (command==command_add)
            {
                    long result=0;
                    for (int i=1;i<expressions.size();i++)
                    {
                        int val=0;
                        if (!Utils::StringUtils::int_parse(expressions[i], val))        // преобразуем строку в int
                            return Result(false, "wrong argument \""+expressions[i]+"\"");

                        result+=val;                                                    // вычисляем результат
                    }
                    return Result(true, std::to_string(result));                        // возвращаем результат
            }
        }
        else
        {
            return Result(false, "command add, not enough parameters");         // возвращаем ошибку
        }
        return Result(false, "wrong command");
    }
    
    bool CommandAdd::matches(std::string command)
    {
        if (command==command_add)
            return true;
        else
            return false;
    }
}

