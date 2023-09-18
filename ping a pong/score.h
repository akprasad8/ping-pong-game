#pragma once

#include <SFML/Graphics.hpp>

class score : public sf::Text
{
public:
	score(sf::Font& font, unsigned int size);
	void IncrementScore();
	void Update();
	int getValue();
private:
	int value;
};