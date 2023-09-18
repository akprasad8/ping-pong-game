#include "score.h"

score::score(sf::Font& font, unsigned int size) : sf::Text("Score: 0", font, size)
{
	this->value = 0;
}

void score::IncrementScore()
{
	this->value += 1;
}
int score::getValue() {
	return this->value;
}
void score::Update()
{
	this->setString("Score: " + std::to_string(this->value));
}