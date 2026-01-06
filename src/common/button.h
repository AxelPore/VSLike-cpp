#pragma once
#include "common_export.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct COMMON_EXPORT Button
{
    sf::CircleShape button;
    sf::Color normalColor;
    sf::Color hoverColor;
    bool isHovered = false;

    Button(float radius, sf::Color normal, sf::Color hover, sf::Vector2f position);

    void update(const sf::RenderWindow& window);
};