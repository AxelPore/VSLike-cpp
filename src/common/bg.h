#pragma once
#include "common_export.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


struct COMMON_EXPORT Background
{
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    Background(int widthWindow, int heightWindow, std::string imgFilePath);

    int loading_bg(std::string imgFilePath);
};