/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** moving_shape.h
*/

#ifndef MOVING_SHAPE_H
    #define MOVING_SHAPE_H

    #include <SFML/Graphics.hpp>

class MovingShape {
    public:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
};

#endif //MOVING_SHAPE_H
