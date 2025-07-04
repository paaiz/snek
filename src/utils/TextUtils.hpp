#pragma once
#include <SFML/Graphics.hpp>

inline void centerText(sf::Text& text, const sf::RenderWindow& window, float offsetY = 0.f) {
    sf::FloatRect bounds = text.getLocalBounds();

    text.setOrigin(bounds.left + bounds.width / 2.f,
                   bounds.top + bounds.height / 2.f);

    sf::Vector2u winSize = window.getSize();
    text.setPosition(winSize.x / 2.f, winSize.y / 2.f + offsetY);
}
