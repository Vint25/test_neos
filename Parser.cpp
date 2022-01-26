#include <vector>
#include <algorithm>
#include <memory>
#include "Parser.h"
#include "Utils.h"
#include "CommandAdd.h"
#include "CommandSub.h"
#include "CommandMult.h"
#include "CommandConcat.h"

namespace CLI
{
    
    Parser::Parser()    // конструктор
    {
        workers.push_back(std::shared_ptr<CommandAdd>(new CommandAdd()));   //Создаем обработчики
        workers.push_back(std::shared_ptr<CommandSub>(new CommandSub()));   //Для добавления нового обработчика, создаем класс обработчика и добавляем его тут
        workers.push_back(std::shared_ptr<CommandMult>(new CommandMult()));
        workers.push_back(std::shared_ptr<CommandConcat>(new CommandConcat()));
    }

    Parser::~Parser() //вуструктор
    {
    }
    
    Result Parser::exec_command(std::vector<std::string> expressions)           // разбор и выполнение команды
    {
        if (expressions.size()>0)
        {
            bool command_ok=false;
            std::string command=Utils::StringUtils::trim(Utils::StringUtils::to_lower(expressions[0]));  //обрезаем пробелы вначале и вконце, и приводим к нижнему регистру


            for (int i=0;i<workers.size();++i)
            {
                if (workers[i]->matches(command))              // проверяем тип команды
                    return workers[i]->exec(expressions);      // если команда верная для обработчика, то выполняем
            }

            
            if (command==command_quit)                      // если ввели quit то выставляем флаг завершения работы
            {
                running=false;
                return Result(true, "bye");
            }

            return Result(false, "wrong command");                              // возврат ошибки команда не была распознана
        }
        else
        {
            return Result(false, "empty argument");                             // возврат ошибки нет параметров
        }
    }

    Result Parser::run(std::string command)                                     // выполнение команды
    {                                                                           // парсим команды и выполняем
        std::vector<std::string> expressions;
        auto start_expression_it=command.begin();                               //тут будем хранить позицию начала следующего параметра в строке
        for (auto current_ch_it=command.begin();current_ch_it!=command.end();++current_ch_it)  // перебераем символы строки
        {
            switch (*current_ch_it)                                             // 
            {
                case ' ':                                                       // обрабатываем пробел, он у нас разделитель
                {
                    std::string expression = std::string(start_expression_it, current_ch_it);  // выделяем параметр
                    if (expression.size()>0 && expression!=" ")                                // и сохраняем его, если не пустой
                        expressions.push_back(expression);                                      
                    start_expression_it=current_ch_it+1;                        // обновляем позицию, начала следующего параметра
                }
                    break;

                case '\"':                                                      // обрабатываем кавычки
                {
                    auto current_expression_end=std::find(current_ch_it+1, command.end(),'\"');  // находим следующую кавычку, это будет окончание строки

                    if (current_expression_end==command.end())
                    {
                        return Result(false, "Error parse expression");
                    }

                    std::string txt_expression = std::string(current_ch_it+1, current_expression_end);   // выделяем строку
                    expressions.push_back(txt_expression);                                              // вставляем строку в список
                    current_ch_it=current_expression_end;
                    start_expression_it=current_expression_end+1;               // обновляем позицию, начала следующего параметра
                }
                    break;

                case '(':                                                       // обрабатываем скобки
                {
                    
                    if (start_expression_it!=current_ch_it)            //это если у нас пропущен пробел и скобка сразу открывается, без пробела такая ситуация тоже будет работать
                    {
                        std::string expression = std::string(start_expression_it, current_ch_it);
                        if (expression.size()>0 && expression!=" ")
                            expressions.push_back(expression);
                    }
                    
                    //Поиск парной скобки
                    int end_pos=0;
                    std::string other_command_string=std::string(current_ch_it+1, command.end()); //выделяем подстроку в которой будем искать парную скобку
                    
                    int bkt_count=0;//количество открытых скобок                    
                    for (int i=0;i<other_command_string.size();++i)
                    {
                        if (other_command_string[i]==')')
                        {
                            if (bkt_count==0)
                            {
                                end_pos=i;
                                break;
                            }
                            else
                                --bkt_count;
                        }
                        if (other_command_string[i]=='(')
                            ++bkt_count;
                    }
                    

                    std::string sub_expression = other_command_string.substr(0,end_pos); //Выделяем подстроку в скобках

                    
                    Result result=run(sub_expression);         /// Выполняем эту строку
                    if (result.result)
                        expressions.push_back(result.value);   // Результат выполнения используем
                    else
                        return result;                          // Если результат с ошибкой, возвращаем ошибку

                    current_ch_it=current_ch_it+end_pos+1;  //увеличиваем позицию, на следующий символ за скобкой.
                    start_expression_it=current_ch_it+1;  // обновляем позицию, начала следующего параметра
                }
                    break;

                default:
                    break;
            }

        }

        if (start_expression_it!=command.end())             // если что-то осталось в строке, тоже выделяем
        {
            std::string expression = std::string(start_expression_it, command.end());
            expressions.push_back(expression);
            start_expression_it=command.end();
        }

        return exec_command(expressions);       // возвращаем результат выполнения распарсеной команды
    }
    
    bool Parser::isRun()
    {
        return running;
    }

}