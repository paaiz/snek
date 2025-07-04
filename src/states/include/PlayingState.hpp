#pragma once
#include "GameState.hpp"
#include "StateManager.hpp"
#include "../../include/Snake.hpp"
#include "../../include/Food.hpp"
#include <SFML/Graphics.hpp>

class PlayingState : public GameState {
private:
    Snake snake;
    Food food;

    sf::Font font;
    sf::Text gameOverText;

    bool gameOver;

public:
    PlayingState();
    void handleInput(sf::RenderWindow& window, StateManager& manager) override;
    void update(StateManager& manager) override;
    void draw(sf::RenderWindow& window) override;
};
