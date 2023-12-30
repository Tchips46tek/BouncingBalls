/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** game_value.h
*/

#ifndef GAME_VALUE_H
    #define GAME_VALUE_H

    #include <SFML/Graphics.hpp>
    #include "moving_shape.h"

    #define WIN game_value->window
    #define BALLS game_value->balls

class GameValue {
    public:
    sf::RenderWindow *window {
    };
    MovingShape *balls {
    };
    sf::Clock gravity_clock;
};

#endif //GAME_VALUE_H
