cmake_minimum_required(VERSION 3.10)
project(libprog-Atividades C)

add_library(libprog-Atividades STATIC
        pila.c
        fila.c
        list.c
)

target_include_directories(libprog-Atividades PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(libprog-Atividades PROPERTIES
        C_STANDARD 23
        C_STANDARD_REQUIRED YES
)