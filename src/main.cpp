#include <SFML/Graphics.hpp>
#include "states/include/StateManager.hpp"
#include "states/include/MainMenuState.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snek");
    window.setFramerateLimit(10);

    StateManager manager;
    manager.setState(std::make_unique<MainMenuState>());

    while (window.isOpen()) {
        if (manager.getState()) {
            manager.getState()->handleInput(window, manager);
            manager.getState()->update(manager);
            manager.getState()->draw(window);
        }
    }

    return 0;
}
