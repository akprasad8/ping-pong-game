
#include <SFML/Graphics.hpp>
#include "result.h"
#include "mainMenu.h"


void result::Initialize(std::shared_ptr<sf::RenderWindow> window)
{

    this->font = std::make_shared<sf::Font>();
    this->font->loadFromFile("Graphics/Montague.ttf");


    float titleFontSizePercentage = 0.19f;
    float buttonFontSizePercentage = 0.1f;

    int titleFontSize = static_cast<int>(window->getSize().y * titleFontSizePercentage);
    int buttonFontSize = static_cast<int>(window->getSize().y * buttonFontSizePercentage);

    this->title = std::make_shared<sf::Text>("Winner", *this->font, titleFontSize);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4);

    this->winPlayer = std::make_shared<sf::Text>(WinPlayer, *this->font, buttonFontSize);
    this->winPlayer->setOrigin(this->winPlayer->getGlobalBounds().width / 2, this->winPlayer->getGlobalBounds().height / 2);
    this->winPlayer->setPosition(window->getSize().x / 2, window->getSize().y / 2);

}



void result::Update(std::shared_ptr<sf::RenderWindow> window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        coreState.SetState(std::make_unique<mainMenu>());
    }
}

void result::Render(std::shared_ptr<sf::RenderWindow> window)
{
    this->winPlayer->setFillColor(sf::Color::Cyan);
    window->draw(*this->title);
    window->draw(*this->winPlayer);

}

void result::Destroy(std::shared_ptr<sf::RenderWindow> window) {}