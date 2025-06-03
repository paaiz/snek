#pragma once
#include <SFML/Graphics.hpp>

class Food {
public:
    Food(int blockSize, int width, int height);

    void respawn();
    sf::Vector2i getPosition() const;
    void draw(sf::RenderWindow& window);

private:
    sf::Vector2i position;
    int blockSize;
    int width, height;
};
