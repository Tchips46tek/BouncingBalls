/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** get_error.cpp
*/

#include <iostream>
#include <ostream>
#include <algorithm>

static bool str_is_num(std::string_view str) {

    return std::all_of(str.begin(), str.end(), [](char c) {return std::isdigit(c) != 0;});
}

bool get_error(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr<<"Usage : ./{name} <Balls number>"<<std::endl;
        return true;
    }
    if (!str_is_num(std::string_view(argv[1]))) {
        std::cerr<<"Invalid balls number"<<std::endl;
        return true;
    }
    return false;
}
