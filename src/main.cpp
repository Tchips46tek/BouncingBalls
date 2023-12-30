/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** main.cpp
*/

#include "main.h"

int main(int argc, char const *argv[]) {
    if (get_error(argc, argv)) {
        return EXIT_FAIL;
    }

    return main_game(argv[1]);
}
