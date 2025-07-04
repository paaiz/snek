#include "include/PlayingState.hpp"
#include "include/MainMenuState.hpp" // Kalau kamu mau bisa balik ke menu
#include <SFML/Window/Event.hpp>

PlayingState::PlayingState()
    : snake(20, 800, 600), food(20, 800, 600), gameOver(false) {

    font.loadFromFile("./src/assets/fonts/arial.ttf");

    gameOverText.setFont(font);
    gameOverText.setString("Game Over!\nPress ENTER to restart\nPress ESC to quit");
    gameOverText.setCharacterSize(28);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(800 / 2 - 180, 600 / 2 - 40);
}

void PlayingState::handleInput(sf::RenderWindow& window, StateManager& manager) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (!gameOver) {
                if (event.key.code == sf::Keyboard::Up) snake.setDirection(UP);
                if (event.key.code == sf::Keyboard::Down) snake.setDirection(DOWN);
                if (event.key.code == sf::Keyboard::Left) snake.setDirection(LEFT);
                if (event.key.code == sf::Keyboard::Right) snake.setDirection(RIGHT);
            }

            if (gameOver) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close(); // Atau bisa manager.setState(std::make_unique<MainMenuState>())
                } else if (event.key.code == sf::Keyboard::Enter) {
                    // Restart state
                    manager.setState(std::make_unique<PlayingState>());
                }
            }
        }
    }
}

void PlayingState::update(StateManager& manager) {
    if (!gameOver) {
        snake.move();

        auto head = snake.getHeadPosition();
        auto foodPos = food.getPosition();

        // Check food collision
        if (head.x == foodPos.x && head.y == foodPos.y) {
            snake.grow();
            food.respawn();
        }

        // Check collision
        if (snake.checkSelfCollision() || snake.isOutOfBounds()) {
            gameOver = true;
        }
    }
}

void PlayingState::draw(sf::RenderWindow& window) {
    window.clear();
    food.draw(window);
    snake.draw(window);
    if (gameOver) {
        window.draw(gameOverText);
    }
    window.display();
}
