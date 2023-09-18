#pragma once
#include "gameState.h"
#include "paddlePlayer.h"
#include "ball.h"
#include "score.h"

class mainGame : public tinyState
{
public:
	void Initialize(std::shared_ptr<sf::RenderWindow> window);
	void Update(std::shared_ptr<sf::RenderWindow> window);
	void Render(std::shared_ptr<sf::RenderWindow> window);
	void Destroy(std::shared_ptr<sf::RenderWindow> window);
private:
	std::shared_ptr < paddlePlayer> player1;
	std::shared_ptr < paddlePlayer> player2;
	std::shared_ptr < Ball> ballObject;
	std::shared_ptr < score> score1;
	std::shared_ptr < score> score2;

	std::shared_ptr < sf::Font> font;
};
