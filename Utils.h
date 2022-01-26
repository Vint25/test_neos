#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_
#include <algorithm>
#include <string>

namespace Utils
{
    class StringUtils   //Мелкие утилиты со строками
    {
        public:
        inline static std::string ltrim(std::string s) //Обрезание пробелов слева
        {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) 
            {
                return !std::isspace(ch);
            }));
            return s;
        }

        inline static std::string rtrim(std::string s) //Обрезание пробелов справа
        {
            s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) 
            {
                return !std::isspace(ch);
            }).base(), s.end());
            return s;
        }

        inline static std::string trim(std::string s) // Обрезание пробелов с обоих строн строки
        {
            ltrim(s);
            rtrim(s);
            return s;
        }


        inline static std::string to_lower(std::string data)  // Приведение к нижнему регистру
        {
            std::transform(data.begin(), data.end(), data.begin(),
                [](unsigned char c){ return std::tolower(c); });
                return data;
        }

        inline static bool int_parse(std::string value, int &result)  // Парсинг строки с int значениями
        {
            try
            {
                result=std::stoi(value);
                return true;
            }
            catch(...)
            {
                return false;
            }
        }
    };
}

#endif /* STRINGUTILS_H_ */