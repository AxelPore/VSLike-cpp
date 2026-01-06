#pragma once
#include "common_export.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "common/objectCenter.h"
#include "common/button.h"

struct COMMON_EXPORT Text
{
	sf::Font font;
	sf::Text text;
    Text(std::string string, float size, sf::Color color, std::string fontFilePath);
	int loadFont(std::string fontFilePath);
};