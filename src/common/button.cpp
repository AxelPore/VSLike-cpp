#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "button.h"

Button::Button(float radius, sf::Color normalColor, sf::Color hoverColor, sf::Vector2f position) {
	button.setRadius(radius);
	button.setFillColor(normalColor);
	button.setPosition(position);
}

void Button::update(const sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	if (button.getGlobalBounds().contains(mousePosF)) {
		isHovered = true;
        button.setFillColor(hoverColor);
	} else {
		isHovered = false;
		button.setFillColor(normalColor);
	}
}