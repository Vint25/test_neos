/* 
 * File:   Response.cpp
 * Author: root
 * 
 * Created on 25 января 2022 г., 8:19
 */
#include <utility>
#include "Result.h"

namespace CLI
{
    Result::Result()  // конструктор п умолчанию
    {
        error_message="";
        result=false;
        value="";
    }

    Result::Result(bool result, std::string message) // конструктор с параметрами
    {
        if (result)
        {
            this->error_message="";
            this->result=true;
            this->value=message;
        }
        else
        {
            this->error_message=message;
            this->result=false;
            this->value="";
        }
    }

    Result::Result(const Result& copy) // конструктор копирования
    {
        this->error_message=copy.error_message;
        this->result=copy.result;
        this->value=copy.value;
    }

    Result& Result::operator=(const Result& copy)  /// оператор копирования
    {
        this->error_message=copy.error_message;
        this->result=copy.result;
        this->value=copy.value;
        return *this;
    }

    Result::Result(const Result&& copy)   // конструктор перемещения
    {
        this->error_message=std::move(copy.error_message);
        this->result=copy.result;
        this->value=std::move(copy.value);
    }

    Result& Result::operator=(const Result&& copy) // оператор перемещения
    {
        this->error_message=std::move(copy.error_message);
        this->result=copy.result;
        this->value=std::move(copy.value);
        return *this;
    }

    Result::~Result() // деструктор
    {
    }
}
