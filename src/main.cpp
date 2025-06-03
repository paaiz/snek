#include <SFML/Graphics.hpp>
#include <ctime>
#include "include/Snake.hpp"
#include "include/Food.hpp"

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int WIDTH = 800;
    const int HEIGHT = 600;
    const int BLOCK_SIZE = 20;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "its a snek!");
    window.setFramerateLimit(10);

    Snake snake(BLOCK_SIZE, WIDTH, HEIGHT);
    Food food(BLOCK_SIZE, WIDTH, HEIGHT);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text gameOverText("Game Over!\nPress ENTER to restart\nPress ESC to quit", font, 28);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(WIDTH / 2 - 180, HEIGHT / 2 - 40);

    bool gameOver = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (!gameOver) {
                    if (event.key.code == sf::Keyboard::Up) snake.setDirection(UP);
                    if (event.key.code == sf::Keyboard::Down) snake.setDirection(DOWN);
                    if (event.key.code == sf::Keyboard::Left) snake.setDirection(LEFT);
                    if (event.key.code == sf::Keyboard::Right) snake.setDirection(RIGHT);
                }

                if (gameOver) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    } else if (event.key.code == sf::Keyboard::Enter) {
                        snake = Snake(BLOCK_SIZE, WIDTH, HEIGHT);
                        food = Food(BLOCK_SIZE, WIDTH, HEIGHT);
                        gameOver = false;
                    }
                }
            }
        }

        if (!gameOver) {
            snake.move();

            // Collision with food
            auto head = snake.getHeadPosition();
            auto foodPos = food.getPosition();
            if (head.x == foodPos.x && head.y == foodPos.y) {
                snake.grow();
                food.respawn();
            }

            // Self-collision
            if (snake.checkSelfCollision()) {
                gameOver = true;
            }
        }

        window.clear();
        food.draw(window);
        snake.draw(window);
        if (gameOver) window.draw(gameOverText);
        window.display();
    }

    return 0;
}
