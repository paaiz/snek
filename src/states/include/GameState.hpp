#pragma once
#include <SFML/Graphics.hpp>

class StateManager;

class GameState {
public:
    virtual void handleInput(sf::RenderWindow& window, StateManager& manager) = 0;
    virtual void update(StateManager& manager) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual ~GameState() {}
};
