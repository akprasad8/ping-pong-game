#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class tinyState
{
public:
    virtual void Initialize(std::shared_ptr<sf::RenderWindow> window){}
    virtual void Update(std::shared_ptr<sf::RenderWindow> window){}
    virtual void Render(std::shared_ptr<sf::RenderWindow> window){}
    virtual void Destroy(std::shared_ptr<sf::RenderWindow> window){}
};

class gameState
{
public:
    gameState() { this->state = nullptr;}
    void SetWindow(std::shared_ptr<sf::RenderWindow> window){ this->window = window; }
    void SetState(std::shared_ptr<tinyState> state){
        if (this->state)
        {
            this->state->Destroy(this->window);
        }
        this->state = state;
        if (this->state)
        {
            this->state->Initialize(this->window);
        }}
    void Update() {
        if (this->state)
        {
            this->state->Update(this->window);
        }
    }
    void Render()
    {
        if (this->state)
        {
            this->state->Render(this->window);
        }
    }
    ~gameState()
    {
        if (this->state)
        {
            this->state->Destroy(this->window);
        }
    }

private:
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<tinyState> state;
};

extern gameState coreState;
extern bool quitGame;
extern float deltaTime;
extern int gameVelocity;
extern int matchpoint;
extern std::string WinPlayer;