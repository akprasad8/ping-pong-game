#pragma once

#include <SFML/Graphics.hpp>
#pragma once
#include <string>
#include <memory>

class Entity : public sf::Sprite
{
public:
    Entity()
    {
        texture = std::make_shared<sf::Texture>();
    }

    void Load(std::string filename)
    {
        texture->loadFromFile("Graphics/sprite/" + filename);
        setTexture(*texture);
    }

    virtual void Update()
    {
        move(velocity);
    }

    bool CheckCollision(std::shared_ptr<Entity> entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }

protected:
    sf::Vector2f velocity;

private:
    std::shared_ptr<sf::Texture> texture;
};
