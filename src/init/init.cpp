/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** init.cpp
*/

#include <iostream>
#include "init.h"

GameValue* init(int ball_number) {
    auto *game_value = new GameValue();
    WIN = new sf::RenderWindow(sf::VideoMode(2000, 1000), "SFML template");
    BALLS = new MovingShape[ball_number];
    sf::Clock gravityClock;

    for (int i = 0; i < ball_number; i++) {
        float radius = (15.0f + (random() % 15)) / 2;

        BALLS[i].shape = sf::CircleShape(radius);
        BALLS[i].velocity = sf::Vector2f( (random() % 30) * (random() % 2 == 0 ? 1 : -1), -(random() % 20));
        BALLS[i].acceleration = sf::Vector2f(0, 1);
        BALLS[i].shape.setOrigin(radius, radius);
        BALLS[i].shape.setPosition(random() % 2000, random() % 800);

        BALLS[i].shape.setFillColor(sf::Color(random() % 255, random() % 255, random() % 255, 255));
    }

    return game_value;
}
