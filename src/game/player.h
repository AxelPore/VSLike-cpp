#pragma once
#include "game_export.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace game
{
	constexpr int FRAME_WIDTH = 32;
	constexpr int FRAME_HEIGHT = 32;

	enum class Direction:std::int32_t
	{
		Idle = 4,
		Left = 1,
		Right = 2,
		Up = 3,
		Down = 0
	};

	struct GAME_EXPORT Player
	{
		sf::Sprite player;
        sf::Texture texture;
		Direction direction = Direction::Down;
        Direction lastDirection = Direction::Down;
		int frame = 0;
		float speed = 2.0f;

        int loadPlayerTexture(std::string imgFilePath);
		Direction updateDirection();
        void movePlayer();
        void animate();
    };
	
} 