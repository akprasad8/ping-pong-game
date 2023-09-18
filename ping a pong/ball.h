#pragma once

#include <SFML/Audio.hpp>
#include "paddlePlayer.h"
#include "score.h"
#include <memory>

class Ball : public Entity
{
public:
    Ball(std::shared_ptr<score> score1, std::shared_ptr<score> score2, std::shared_ptr<paddlePlayer> player1, std::shared_ptr<paddlePlayer> player2);
    void Update(std::shared_ptr < sf::RenderWindow> window);
    void Reset(std::shared_ptr < sf::RenderWindow> window);
    ~Ball();

private:
    std::shared_ptr<score> score1;
    std::shared_ptr<score> score2;
    std::shared_ptr<paddlePlayer> player1;
    std::shared_ptr<paddlePlayer> player2;

    std::shared_ptr < sf::SoundBuffer> buffer;
    std::shared_ptr < sf::Sound> sound;
};
