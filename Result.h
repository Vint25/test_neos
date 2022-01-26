#ifndef RESULT_H_
#define RESULT_H_

#include <string>

namespace CLI
{
    class Result  //класс для хранения результата
    {
    public:
        std::string error_message="";   // текст ошибки
        bool result=false;              // успешный или неуспшный
        std::string value="";           // значение самого результата
        Result();
        Result(bool result, std::string message);   // конструктор с параметрами
        Result(const Result& copy);                 // конструктор копирования
        Result& operator=(const Result& copy);      // оператор копирования
        Result(const Result&& copy);                // конструктор перемещения
        Result& operator=(const Result&& copy);     // оператор перемещения
        virtual ~Result();                          // деструктор
    };
}

#endif /* RESULT_H_ */