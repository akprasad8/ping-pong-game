#include <SFML/Graphics.hpp>
#include "gameState.h"
#include "mainMenu.h"
#include <memory>
#include <SFML/Audio.hpp>

gameState coreState;
bool quitGame = false;
float deltaTime = 0.0f;
int frameRate = 60;
int gameVelocity = 100;
int matchpoint = 1;
std::string WinPlayer = "Player1";
int main()
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(
    sf::VideoMode::getFullscreenModes()[0], "Ping", sf::Style::Fullscreen);

    coreState.SetWindow(window);
    coreState.SetState(std::make_unique<mainMenu>());

    sf::Clock clock;
    window->setFramerateLimit(frameRate);

    sf::SoundBuffer musicBuffer;
    musicBuffer.loadFromFile("Sounds/music.wav");
    sf::Sound music(musicBuffer);

    music.setLoop(true);
    music.setVolume(10);
    music.play();

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        deltaTime = clock.restart().asSeconds();
        gameVelocity = 700.0f * deltaTime;
        window->clear(sf::Color::Black);

        coreState.Update();
        coreState.Render();

        window->display();

        if (quitGame) { window->close(); }
        
        
    }

    return 0;
}
