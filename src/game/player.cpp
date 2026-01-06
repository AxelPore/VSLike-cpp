#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"


namespace game
{

    int Player::loadPlayerTexture(std::string imgFilePath)
    {
        if (!texture.loadFromFile(imgFilePath))
            return EXIT_FAILURE;
        player.setTexture(texture);
        player.setTextureRect(sf::IntRect(frame * FRAME_WIDTH, static_cast<int>(direction) * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));
        return EXIT_SUCCESS;
    }

    Direction Player::updateDirection()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            return Direction::Left;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            return Direction::Right;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            return Direction::Up;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            return Direction::Down;
        return Direction::Idle;
    }

    void Player::movePlayer()
    {
        switch (direction)
        {
            case Direction::Left:
                player.move(-speed, 0);
                break;
            case Direction::Right:
                player.move(speed, 0);
                break;
            case Direction::Up:
                player.move(0, -speed);
                break;
            case Direction::Down:
                player.move(0, speed);
                break;
            case Direction::Idle:
                break;
        }
    }

    void Player::animate()
    {
        direction = updateDirection();

        if (direction != Direction::Idle)
        {
            if (direction == lastDirection)
                frame = (frame + 1) % 3;
            else
                frame = 0;

            movePlayer();
            lastDirection = direction;
        }
        else
        {
            frame = 1;
            direction = lastDirection;
        }
        player.setTextureRect(sf::IntRect(frame * FRAME_WIDTH, static_cast<int>(direction) * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));

    }

}
