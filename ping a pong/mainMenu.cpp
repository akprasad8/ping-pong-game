#include <SFML/Graphics.hpp>
#include "mainMenu.h"
#include "mainGame.h"

void mainMenu::Initialize(std::shared_ptr<sf::RenderWindow> window)
{
    this->selected = 0;

    this->font = std::make_shared<sf::Font>();
    this->font->loadFromFile("Graphics/Montague.ttf");

 
    float titleFontSizePercentage = 0.19f; 
    float buttonFontSizePercentage = 0.1f; 

    int titleFontSize = static_cast<int>(window->getSize().y * titleFontSizePercentage);
    int buttonFontSize = static_cast<int>(window->getSize().y * buttonFontSizePercentage);

    this->title = std::make_shared<sf::Text>("Ping", *this->font, titleFontSize);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4); 

    this->play = std::make_shared<sf::Text>("Play", *this->font, buttonFontSize);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
    this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);

  
    this->quit = std::make_shared<sf::Text>("Quit", *this->font, buttonFontSize);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
    this->quit->setPosition(window->getSize().x / 2, this->play->getPosition().y + 2*this->play->getGlobalBounds().height);
}




void mainMenu::Update(std::shared_ptr<sf::RenderWindow> window)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
    {
        this->selected = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
    {
        this->selected = 1;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
    {
        switch (this->selected)
        {
        case 0:
            coreState.SetState(std::make_unique<mainGame>());
            break;
        case 1:
            quitGame = true;
            break;
        }
    }
    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void mainMenu::Render(std::shared_ptr<sf::RenderWindow> window)
{
    this->play->setFillColor(sf::Color::White);
    this->quit->setFillColor(sf::Color::White);
    switch (this->selected)
    {
    case 0:
        this->play->setFillColor(sf::Color::Green);
        break;
    case 1:
        this->quit->setFillColor(sf::Color::Green);
        break;
    }
    window->draw(*this->title);
    window->draw(*this->play);
    window->draw(*this->quit);
}

void mainMenu::Destroy(std::shared_ptr<sf::RenderWindow> window){}
    