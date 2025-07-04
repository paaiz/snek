#include "include/StateManager.hpp"

void StateManager::setState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}

GameState* StateManager::getState() {
    return currentState.get();
}
