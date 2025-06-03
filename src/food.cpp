#include "include/Food.hpp"
#include <cstdlib>

Food::Food(int blockSize, int width, int height)
    : blockSize(blockSize), width(width), height(height) {
    respawn();
}

void Food::respawn() {
    position.x = rand() % (width / blockSize);
    position.y = rand() % (height / blockSize);
}

sf::Vector2i Food::getPosition() const {
    return position;
}

void Food::draw(sf::RenderWindow& window) {
    sf::RectangleShape square(sf::Vector2f(blockSize - 1, blockSize - 1));
    square.setFillColor(sf::Color::Red);
    square.setPosition(position.x * blockSize, position.y * blockSize);
    window.draw(square);
}
