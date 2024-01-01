/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** moving_shape.h
*/

#ifndef MOVING_SHAPE_H
    #define MOVING_SHAPE_H

    #define STRENGTH_LOSS_ON_EDGE_BOUNCE 0.91

    #include <SFML/Graphics.hpp>

class MovingShape {
    public:
    void edgeChoc() {
        this->velocity.x *= STRENGTH_LOSS_ON_EDGE_BOUNCE;
        this->velocity.y *= STRENGTH_LOSS_ON_EDGE_BOUNCE;
    }
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float gravity_power{1.0};
};

#endif //MOVING_SHAPE_H
