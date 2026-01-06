#pragma once
#include "game_export.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace game
{
    struct GAME_EXPORT BouleDeFeu
    {
        sf::CircleShape sprite;
        float speed;
        BouleDeFeu();
        void apparition(float startX, float startY, const sf::RenderWindow& window);
    };
} 