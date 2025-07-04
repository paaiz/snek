#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Segment {
    int x, y;
    Segment(int _x, int _y) : x(_x), y(_y) {}
};

class Snake {
public:
    Snake(int blockSize, int width, int height);

    void move();
    void grow();
    bool checkCollision();
    bool checkSelfCollision() const;
    void setDirection(Direction newDir);
    Direction getDirection() const;
    Segment getHeadPosition() const;
    void draw(sf::RenderWindow& window);
    bool isOutOfBounds() const;

private:
    std::vector<Segment> body;
    Direction dir;
    int blockSize;
    int width, height;
};
