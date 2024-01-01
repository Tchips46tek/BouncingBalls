/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** draw.cpp
*/

#include "draw.h"

void draw(GameValue *game_value) {
    WIN->clear();
    for (MovingShape *ball : BALLS) {
        WIN->draw(ball->shape);
    }
    WIN->display();
}
