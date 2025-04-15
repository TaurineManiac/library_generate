cmake_minimum_required(VERSION 3.20)
project(megagenerate)

set(CMAKE_CXX_STANDARD 17)

# Указываем, что это динамическая библиотека
add_library(megagenerate SHARED generate.cpp)  # Изменили имя на megagenerate

# Указываем путь к заголовочному файлу
target_include_directories(megagenerate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})