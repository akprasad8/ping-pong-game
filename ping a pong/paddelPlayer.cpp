#include "paddlePlayer.h"
#include "gameState.h"
paddlePlayer::paddlePlayer(int playerNumber, std::shared_ptr<sf::RenderWindow> window)
{
    this->playerNumber = playerNumber;

    switch (this->playerNumber)
    {
    case 0:
        this->Load("paddle1.png");
        break;
    default:
        this->Load("paddle2.png");
        break;
    }

    if (playerNumber == 0)
    {
        this->move(10.0f, window->getSize().y / 2.0f);
    }
    else
    {
        this->move(window->getSize().x - getGlobalBounds().width - 10.0f, window->getSize().y / 2.0f);
    }
}

void paddlePlayer::Update(std::shared_ptr<sf::RenderWindow> window)
{
    switch (this->playerNumber)
    {
    case 0:
        this->velocity.y = gameVelocity * (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W));
        break;
    default:
        this->velocity.y = gameVelocity * (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up));
        break;
    }
    Entity::Update();

    if (this->getPosition().y < 0)
    {
        this->move(0, gameVelocity);
    }
    if (this->getPosition().y + getGlobalBounds().height > window->getSize().y)
    {
        this->move(0, -gameVelocity);
    }
}
