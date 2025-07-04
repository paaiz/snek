#pragma once
#include "GameState.hpp"
#include "StateManager.hpp"
#include <SFML/Graphics.hpp>

class MainMenuState : public GameState {
private:
    sf::Font font;
    sf::Text titleText, titleText2, playText;
    sf::Clock colorClock;

public:
    MainMenuState();

    void handleInput(sf::RenderWindow& window, StateManager& manager) override;
    void update(StateManager& manager) override;
    void draw(sf::RenderWindow& window) override;
};
