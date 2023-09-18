#include "ball.h"
#include "gameState.h"


Ball::Ball(std::shared_ptr<score> score1, std::shared_ptr<score> score2, std::shared_ptr<paddlePlayer> player1, std::shared_ptr<paddlePlayer> player2)
{
    this->Load("ball.png");
    this->score1 = score1;
    this->score2 = score2;
    this->player1 = player1;
    this->player2 = player2;

    this->buffer = std::make_shared<sf::SoundBuffer>();
    this->buffer->loadFromFile("Sounds/bounce.wav");
    this->sound = std::make_shared<sf::Sound>(*this->buffer);
}

void Ball::Update(std::shared_ptr < sf::RenderWindow> window)
{
    if (this->CheckCollision(this->player1) || this->CheckCollision(this->player2))
    {
        this->velocity.x *= -1;
        this->sound->play();
    }
    if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
    {
        this->velocity.y *= -1;
        this->sound->play();
    }

    if (this->getPosition().x < 0 )
    {
        this->score2->IncrementScore();
        this->Reset(window);
    }
    if (this->getPosition().x + this->getGlobalBounds().width > window->getSize().x)
    {
        this->score1->IncrementScore();
        this->Reset(window);
    }
    
    Entity::Update();
    
}

void Ball::Reset(std::shared_ptr < sf::RenderWindow> window)
{
    this->velocity.x = gameVelocity;
    this->velocity.y = gameVelocity;
    this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
    this->player1->setPosition(0, window->getSize().y / 2 + this->player1->getGlobalBounds().height / 4);
    this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 + this->player2->getGlobalBounds().height / 4);
}

Ball::~Ball(){}