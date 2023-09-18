#pragma once

#include "Entity.h"

class paddlePlayer : public Entity
{
public:
	paddlePlayer(int playerNumber, std::shared_ptr<sf::RenderWindow> window);
	void Update(std::shared_ptr<sf::RenderWindow> window);
private:
	int playerNumber;
};