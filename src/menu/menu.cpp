#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "common/button.h"
#include "common/objectCenter.h"
#include "common/text.h"
#include "common/bg.h"
#include "game/game.h"

namespace menu
{

    int menu()
    {
        int widthWindow = 1400, heightWindow = 950;
        sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "Menu", sf::Style::Default);
        Background bg(widthWindow, heightWindow, "assets/bg.jpg");
        window.setVerticalSyncEnabled(true);
        float radius = 100.0f;
        Button StartButton(radius, sf::Color::Green, sf::Color::Yellow, sf::Vector2f(widthWindow / 2 - 450, heightWindow / 2 - 50));
        Button ExitButton(radius, sf::Color::Red, sf::Color::Magenta, sf::Vector2f(widthWindow / 2 + 250, heightWindow / 2 - 50));
        Text StartText("start", 30.0f, sf::Color::Black, "assets/arial.ttf");
        Text ExitText("exit", 30.0f, sf::Color::Black, "assets/arial.ttf");
        center_horizontally(StartButton.button, StartText.text);
        center_horizontally(ExitButton.button, ExitText.text);
        center_vertically(StartButton.button, StartText.text);
        center_vertically(ExitButton.button, ExitText.text);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::Black);
            window.draw(bg.sprite);
            window.draw(StartButton.button);
            window.draw(ExitButton.button);
            window.draw(StartText.text);
            window.draw(ExitText.text);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (StartButton.button.getGlobalBounds().contains(mousePosF))
                {
                    window.close();
                    game::game();
                }
                else if (ExitButton.button.getGlobalBounds().contains(mousePosF))
                {
                    window.close();
                }
            }

            window.display();
        }
        return 0;
    }
}