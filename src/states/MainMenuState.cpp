#include "include/MainMenuState.hpp"
#include "include/PlayingState.hpp"

MainMenuState::MainMenuState() {
    font.loadFromFile("./src/assets/fonts/arial.ttf");

    titleText.setFont(font);
    titleText.setString("It's a Snek!");
    titleText.setCharacterSize(40);
    titleText.setPosition(250, 150);

    playText.setFont(font);
    playText.setString("Press ENTER to Play");
    playText.setCharacterSize(28);
    playText.setPosition(230, 250);
}

void MainMenuState::handleInput(sf::RenderWindow& window, StateManager& manager) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            manager.setState(std::make_unique<PlayingState>()); // Ganti ke Game State
        }
    }
}

void MainMenuState::update(StateManager& manager) {}

void MainMenuState::draw(sf::RenderWindow& window) {
    window.clear();
    window.draw(titleText);
    window.draw(playText);
    window.display();
}
