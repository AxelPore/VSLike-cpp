#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "common/objectCenter.h"
#include "common/button.h"
#include "text.h"



Text::Text(std::string string, float size, sf::Color color, std::string fontFilePath)
{
    loadFont(fontFilePath);
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
}

int Text::loadFont(std::string fontFilePath)
{
    if (!font.loadFromFile(fontFilePath))
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
