/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** draw.cpp
*/

#include "draw.h"

void draw(GameValue *game_value, int ball_number) {
    WIN->clear();
    for (int i = 0; i < ball_number; i++) {
        WIN->draw(game_value->balls[i].shape);
    }
    WIN->display();
}
