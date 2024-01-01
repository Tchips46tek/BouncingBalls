/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** destroy.cpp
*/

#include "destroy.h"

void destroy(GameValue *game_value) {
    WIN->~RenderWindow();
}
