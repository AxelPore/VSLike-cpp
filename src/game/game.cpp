#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "player.h"
#include "bouleDeFeu.h"
#include <iostream>
#include <vector>


namespace game
{

    int game()
    {
        
        sf::RenderWindow window(sf::VideoMode(1400, 950), "Game");
        window.setFramerateLimit(30);

        Player Player;
        if (Player.loadPlayerTexture("assets/character-pack-full_version/sprite_split/character_1/character_1_frame32x32.png") == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }
        Player.player.setPosition(200, 200);


        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
                if (event.type == sf::Event::Closed)
                    window.close();

            Player.animate();

            window.clear(sf::Color::Black);
            window.draw(Player.player);
            window.display();
        }

        return 0;
    }
} 
