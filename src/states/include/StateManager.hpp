#pragma once
#include "GameState.hpp"
#include <memory>

class StateManager {
private:
    std::unique_ptr<GameState> currentState;

public:
    void setState(std::unique_ptr<GameState> newState);
    GameState* getState();
};
