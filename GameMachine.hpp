#pragma once

#include <chrono>

union SDL_Event;
struct SDL_Renderer;

class GameMachine {
public:
    enum class Transition {
        stay,
        exit,
    };

    Transition processEvent(const SDL_Event& event);
    void iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick);
private:
};
