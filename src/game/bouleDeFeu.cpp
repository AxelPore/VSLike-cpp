#include "bouleDeFeu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace game
{
	BouleDeFeu::BouleDeFeu() : speed(1.0f)
	{
		texture.loadFromFile("assets/fireball.png");
		sprite.setTexture(texture);
		sprite.setScale(0.5f, 0.5f);
	}
    void BouleDeFeu::apparition(float startX, float startY, const sf::RenderWindow& window)
	{
		sprite.setPosition(startX, startY);
        window.draw(sprite);
	}
	
}