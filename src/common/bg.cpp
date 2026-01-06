#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "bg.h"

Background::Background(int widthWindow, int heightWindow, std::string imgFilePath)
{
    loading_bg(imgFilePath);

    texture.update(image);

    sprite.setTexture(texture);
    sf::Vector2f targetSize(widthWindow, heightWindow);

    sprite.setScale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
}

int Background::loading_bg(std::string imgFilePath)
{
    if (!image.loadFromFile(imgFilePath))
        return EXIT_FAILURE;

    if (!texture.loadFromImage(image))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
