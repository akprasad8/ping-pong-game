#include "mainGame.h"
#include "mainMenu.h"
#include "result.h"
#include "gameState.h"

void mainGame::Initialize(std::shared_ptr<sf::RenderWindow> window) {
    this->font = std::make_shared<sf::Font>();
    this->font->loadFromFile("Graphics/Montague.ttf");

    //to do soo that size is based on window
    this->score1 = std::make_shared<score>(*font, 64U);
    this->score2 = std::make_shared<score>(*font, 64U);

    sf::Vector2u windowSize = window->getSize();
    this->score2->setPosition(windowSize.x - this->score2->getGlobalBounds().width, 0);

    this->player1 = std::make_shared<paddlePlayer>(0, window);
    this->player2 = std::make_shared<paddlePlayer>(1, window);
    this->ballObject = std::make_shared<Ball>(this->score1, this->score2, this->player1, this->player2);

    this->ballObject->Reset(window);
}
void mainGame::Update(std::shared_ptr<sf::RenderWindow> window) {
    this->ballObject->Update(window);
    this->player1->Update(window);
    this->player2->Update(window);
    this->score1->Update();
    this->score2->Update();

    
    if (this->score2->getValue() == matchpoint ) {
        WinPlayer = "Player2";
        coreState.SetState(std::make_unique<result>());
    }
    else if (this->score1->getValue() == matchpoint) {
        WinPlayer = "Player1";
        coreState.SetState(std::make_unique<result>());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        coreState.SetState(std::make_unique<mainMenu>());
    }
}
void mainGame::Render(std::shared_ptr<sf::RenderWindow> window) {
    window->draw(*this->ballObject);
    window->draw(*this->player1);
    window->draw(*this->player2);
    window->draw(*this->score1);
    window->draw(*this->score2);
}
void mainGame::Destroy(std::shared_ptr<sf::RenderWindow> window) {}
