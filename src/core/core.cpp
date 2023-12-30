/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** move_balls.cpp
*/

#include "core.h"

static void move_balls(MovingShape *balls, int ball_number) {
        for (int i = 0; i < ball_number; i++) {
            if (balls[i].shape.getPosition().x >= 2000 - balls[i].shape.getRadius() || balls[i].shape.getPosition().x <= balls[i].shape.getRadius())
                balls[i].velocity.x *= -1;
            if (balls[i].shape.getPosition().y >= 1000 - balls[i].shape.getRadius())
                balls[i].velocity.y *= -1;
            else
                balls[i].velocity += balls[i].acceleration;
            balls[i].shape.move(balls[i].velocity);
        }
}

void core(GameValue *game_value, int ball_number) {
    if (game_value->gravity_clock.getElapsedTime().asMilliseconds() >= 17) {
        game_value->gravity_clock.restart();
        move_balls(BALLS, ball_number);
    }
}
