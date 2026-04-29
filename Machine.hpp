#pragma once

#include <chrono>

#include <SDL3/SDL.h>


class Machine {
public:
    enum class Transition {
        stay,
        exit
    };

    Transition processEvent(const SDL_Event& event);
    void iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick);

private:
};


void* toVoidStar(Machine* machine);
Machine* toMachine(void* appState);
