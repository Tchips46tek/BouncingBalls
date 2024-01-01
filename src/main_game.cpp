/*
** EPITECH PROJECT, 2023
** cpp_sfml
** File description:
** main_game.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "init.h"
#include "core.h"
#include "draw.h"
#include "destroy.h"

int main_game(char const *ball_number_str) {
    srandom(time(nullptr));
    GameValue *game_value = init(ball_number_str);

    while (WIN->isOpen()) {
        sf::Event event{};
        while (WIN->pollEvent(event)) {
            if (event.type == sf::Event::Closed
            || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
                WIN->close();
        }
        core(game_value);
        draw(game_value);
    }
    destroy(game_value);
    return EXIT_SUCCESS;
}
