/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 24 января 2022 г., 19:25
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Utils.h"
#include "Result.h"
#include "Parser.h"

void run_test();

int main(int argc, char** argv) 
{
    //run_test();
    
    std::cout<<"Hi! Please type the command"<<std::endl;
    CLI::Parser my_parser;  //Создаем парсер
    while (my_parser.isRun())  //Проверяем, что работает
    {
        std::string command="";
        std::getline(std::cin, command);  //Получаем строку с консоли
        
        CLI::Result result=my_parser.run(command);  // Выполняем команду
        
        if (result.result)                                  // Выводим результат
            std::cout<<" Result: "<<result.value<<std::endl;
        else
            std::cout<<" Error: "<<result.error_message<<std::endl;
    }
    return 0;
}


std::string test(std::string command, std::string test_result)
{

    CLI::Parser my_parser;  //Создаем парсер
  
    CLI::Result result=my_parser.run(command);  // Выполняем команду

    if (result.result)                                  // Выводим результат
    {
        std::cout<<"Test: "<<command<<"Result:"<<result.value<<std::endl;
        if (test_result==result.value)
            std::cout<<"Test OK"<<std::endl;
        else
            std::cout<<"Test Error"<<std::endl;
        return result.value;
    }
    else
    {
        std::cout<<"Test: "<<command<<"Error:"<<result.error_message<<std::endl;
        if (test_result==result.error_message)
            std::cout<<"Test OK"<<std::endl;
        else
            std::cout<<"Test Error"<<std::endl;
        return result.error_message;
    }
    
    
}

void run_test()
{
    test("add 5 7 3", "15");
    test("sub -7 \"3\"", "-10");
    test("mult (add 5 3) (sub 5 3)", "16");
    test("concat \"(2 + 2) * 2 = \" (mult 2 (add 2 2))", "(2 + 2) * 2 = 8");

    test("mult (add 5 3)(sub 5 3)", "16");
    test("add 10 (mult 4(mult 1 2))", "18");
    test("add 5(mult 4(mult 1 2))", "13");
    
    test("add \"aaabbb\" 5 (mult 4(mult 1 2))", "wrong argument \"aaaddd\"");
    test("concat \"bbbnnn\" 5 (mult 4(mult 1 2))", "bbbnnn58");
    test("hhuu", "wrong command");
}



