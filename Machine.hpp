#pragma once

#include <chrono>

#include <SDL3/SDL.h>

#include <GameMachine.hpp>
#include <MainMenuMachine.hpp>

class Machine {
public:
    enum class Transition {
        stay,
        exit,
    };

    Transition processEvent(const SDL_Event& event);
    void iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick);

private:
    MainMenuMachine mainMenuMachine;
    GameMachine gameMachine;

    enum class State {
        mainMenu,
        game,
    } current{State::mainMenu};
};


void* toVoidStar(Machine* machine);
Machine* toMachine(void* appState);
