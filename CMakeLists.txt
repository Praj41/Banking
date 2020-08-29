cmake_minimum_required(VERSION 3.10)
project(ATM_Banking_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(ATM_Banking_System main.cpp ATM.cpp ATM.h Bank.cpp Bank.h Admin.cpp Admin.h)
