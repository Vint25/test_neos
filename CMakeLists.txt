cmake_minimum_required(VERSION 3.4)
project(parser)
set(SOURCE main.cpp Result.cpp Parser.cpp CommandSub.cpp CommandMult.cpp CommandConcat.cpp CommandAdd.cpp Command.cpp)
set(HEADER Utils.h Result.h Parser.h CommandSub.h CommandMult.h CommandConcat.h CommandAdd.h Command.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
add_executable(${PROJECT_NAME} ${SOURCE})
