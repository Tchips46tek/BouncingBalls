/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** move_balls.cpp
*/

#include <cmath>
#include <iostream>
#include "core.h"

static void check_ball_collisions(MovingShape *ball, const std::vector<MovingShape*>& balls) {
    for (MovingShape* ballColiding : balls) {
        if (ballColiding == ball)
            continue;
        float x = ball->shape.getPosition().x - ballColiding->shape.getPosition().x;
        float y = ball->shape.getPosition().y - ballColiding->shape.getPosition().y;
        double h = sqrt(pow(x, 2) + pow(y, 2));
        if (ball->shape.getRadius() + ballColiding->shape.getRadius() >= h) {
            double repulsionAngle = atan((double)(y / x));
            double v1 = sqrt(pow(ball->velocity.x, 2) + pow(ball->velocity.y, 2));
            double v2 = sqrt(pow(ballColiding->velocity.x, 2) + pow(ballColiding->velocity.y, 2));
            double m1 = ball->shape.getRadius() / 10;
            double m2 = ballColiding->shape.getRadius() / 10;
            double repulsionPower = (((m1 - m2) / (m1 + m2)) * v1) + (((2 * m2) / (m1 + m2)) * v2);
            double repulsionX = cos(repulsionAngle) * repulsionPower;
            double repulsionY = sin(repulsionAngle) * repulsionPower;
            std::cout<<repulsionX<<'|'<<repulsionY<<'|'<<repulsionPower<<std::endl;
            ball->velocity += sf::Vector2f((float)repulsionX, (float)repulsionY);
        }
    }
}

static bool check_edge_collisions(MovingShape *ball) {
    if (ball->shape.getPosition().x + ball->velocity.x >= 2000 - ball->shape.getRadius()
        || ball->shape.getPosition().x - ball->velocity.x <= ball->shape.getRadius()) {
        ball->velocity.x *= -1;
        ball->edgeChoc();
    }
    if (ball->shape.getPosition().y + ball->velocity.y >= 1000 - ball->shape.getRadius()) {
        ball->velocity.y *= -1;
        ball->edgeChoc();
        return true;
    }
    return false;
}

static void move_balls(const std::vector<MovingShape*>& balls) {
    for (MovingShape* ball : balls) {
        if (!check_edge_collisions(ball)) {
            ball->velocity.x += ball->acceleration.x * ball->gravity_power;
            ball->velocity.y += ball->acceleration.y * ball->gravity_power;
        }
        check_ball_collisions(ball, balls);
        ball->shape.move(ball->velocity);
    }
}

void core(GameValue *game_value) {
    if (game_value->gravity_clock.getElapsedTime().asMilliseconds() >= 17) {
        game_value->gravity_clock.restart();
        move_balls(BALLS);
    }
}
