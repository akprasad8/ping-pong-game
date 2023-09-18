#pragma once

#include "gameState.h"


class mainMenu : public tinyState
{
public:
    void Initialize(std::shared_ptr<sf::RenderWindow> window);
    void Update(std::shared_ptr<sf::RenderWindow> window);
    void Render(std::shared_ptr<sf::RenderWindow> window);
    void Destroy(std::shared_ptr<sf::RenderWindow> window);

private:
    std::shared_ptr<sf::Font> font;
    std::shared_ptr<sf::Text> title;
    std::shared_ptr<sf::Text> play;
    std::shared_ptr<sf::Text> quit;

    int selected;
    bool upKey, downKey;
};

