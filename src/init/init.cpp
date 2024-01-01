/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** init.cpp
*/

#include <iostream>
#include "init.h"

GameValue* init(char const *ball_number_str) {
    auto *game_value = new GameValue();
    WIN = new sf::RenderWindow(sf::VideoMode(2000, 1000), "SFML template");
    for (int i = 0; i < std::stoi(ball_number_str); ++i) {
        BALLS.push_back(new MovingShape());
    }
    sf::Clock gravityClock;

    for (MovingShape* ball : BALLS) {
        float radius = (15.0f + (random() % 15)) / 2;

        ball->shape = sf::CircleShape(radius);
        ball->velocity = sf::Vector2f( (random() % 30) - 15, -(random() % 20) + 1);
        ball->acceleration = sf::Vector2f(0, 1);
        ball->shape.setOrigin(radius, radius);
        ball->shape.setPosition(random() % 2000, random() % 800);

        ball->shape.setFillColor(sf::Color(random() % 255, random() % 255, random() % 255, 255));
    }

    return game_value;
}
