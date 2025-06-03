#include "include/Snake.hpp"

Snake::Snake(int blockSize, int width, int height)
    : blockSize(blockSize), width(width), height(height), dir(RIGHT) {
    body = { Segment(10, 10), Segment(9, 10), Segment(8, 10) };
}

void Snake::setDirection(Direction newDir) {
    if ((dir == UP && newDir != DOWN) ||
        (dir == DOWN && newDir != UP) ||
        (dir == LEFT && newDir != RIGHT) ||
        (dir == RIGHT && newDir != LEFT)) {
        dir = newDir;
    }
}

Direction Snake::getDirection() const {
    return dir;
}

Segment Snake::getHeadPosition() const {
    return body.front();
}

void Snake::move() {
    Segment head = body.front();

    switch (dir) {
        case UP: head.y--; break;
        case DOWN: head.y++; break;
        case LEFT: head.x--; break;
        case RIGHT: head.x++; break;
    }

    // Wrap around
    if (head.x < 0) head.x = width / blockSize - 1;
    if (head.x >= width / blockSize) head.x = 0;
    if (head.y < 0) head.y = height / blockSize - 1;
    if (head.y >= height / blockSize) head.y = 0;

    body.insert(body.begin(), head);
    body.pop_back();
}

void Snake::grow() {
    body.push_back(body.back()); // Duplicate last segment
}

bool Snake::checkSelfCollision() const {
    Segment head = body.front();
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i].x == head.x && body[i].y == head.y) return true;
    }
    return false;
}

void Snake::draw(sf::RenderWindow& window) {
    sf::RectangleShape square(sf::Vector2f(blockSize - 1, blockSize - 1));
    square.setFillColor(sf::Color::Blue);
    for (auto& s : body) {
        square.setPosition(s.x * blockSize, s.y * blockSize);
        window.draw(square);
    }
}
