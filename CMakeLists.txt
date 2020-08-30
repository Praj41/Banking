cmake_minimum_required(VERSION 3.10)
project(ATM_Banking_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Banking_System main.cpp ATM/ATM.cpp ATM/ATM.h Bank/Bank.cpp Bank/Bank.h Admin/Admin.cpp Admin/Admin.h)
