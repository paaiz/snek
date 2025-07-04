#include "include/PlayingState.hpp"
#include "include/MainMenuState.hpp" // Kalau kamu mau bisa balik ke menu
#include <SFML/Window/Event.hpp>

#include "../utils/TextUtils.hpp"

int BLOCK_SIZE = 40;
int WIDTH = 800;
int HEIGHT = 600;

PlayingState::PlayingState()
    : snake(BLOCK_SIZE, WIDTH, HEIGHT), food(BLOCK_SIZE, WIDTH, HEIGHT), gameOver(false) {

    font.loadFromFile("./src/assets/fonts/arial.ttf");

    gameOverText.setFont(font);
    gameOverText.setString("Game Over!\n\nPress ENTER to restart\nPress ESC to go to Main Menu");
    gameOverText.setCharacterSize(28);
    gameOverText.setFillColor(sf::Color::White);
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
                    manager.setState(std::make_unique<MainMenuState>());
                } else if (event.key.code == sf::Keyboard::Enter) {
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
    centerText(gameOverText, window, -50);

    window.clear();
    food.draw(window);
    snake.draw(window);
    if (gameOver) {
        window.draw(gameOverText);
    }
    window.display();
}
