#include "include/MainMenuState.hpp"
#include "include/PlayingState.hpp"

#include "../utils/TextUtils.hpp"

#include <cmath>


MainMenuState::MainMenuState() {
    font.loadFromFile("./src/assets/fonts/arial.ttf");

    titleText.setFont(font);
    titleText.setString("It's a");
    titleText.setCharacterSize(40);

    titleText2.setFont(font);
    titleText2.setString("Snek!");
    titleText2.setCharacterSize(40);
    titleText2.setPosition(titleText.getPosition().x, titleText.getPosition().y + 50);

    playText.setFont(font);
    playText.setString("Press ENTER to Play");
    playText.setCharacterSize(28);
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

void MainMenuState::update(StateManager& manager) {
    float time = colorClock.getElapsedTime().asSeconds();

    // Animasi RGB dengan fungsi sinusoidal
    sf::Uint8 red = static_cast<sf::Uint8>((std::sin(time * 2.0f) + 1.0f) * 127.5f);
    sf::Uint8 green = static_cast<sf::Uint8>((std::sin(time * 2.0f + 2.0f) + 1.0f) * 127.5f);
    sf::Uint8 blue = static_cast<sf::Uint8>((std::sin(time * 2.0f + 4.0f) + 1.0f) * 127.5f);

    titleText2.setFillColor(sf::Color(red, green, blue));
}


void MainMenuState::draw(sf::RenderWindow& window) {
    window.clear();

    sf::FloatRect titleBounds = titleText.getLocalBounds();

    float totalWidth = titleBounds.width + titleText2.getLocalBounds().width;
    float centerX = window.getSize().x / 2.f;

    float startX = centerX - totalWidth / 2.f;
    float y = window.getSize().y / 2.f - 100.f;

    titleText.setPosition(startX, y);
    titleText2.setPosition(startX + titleBounds.width + 15.f, y);

    centerText(playText, window, 20);

    window.clear();
    window.draw(titleText);
    window.draw(titleText2);
    window.draw(playText);
    window.display();
}
