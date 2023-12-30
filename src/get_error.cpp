/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** get_error.cpp
*/

#include <iostream>
#include <ostream>

static bool str_is_num(char const *str) {
    for (const char c : std::string_view(str)) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

bool get_error(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr<<"1 arguments pour le nombre de balles"<<std::endl;
        return true;
    }
    if (!str_is_num(argv[1])) {
        return true;
    }
    return false;
}
