#pragma once

#include <chrono>

#include <GameMachine.hpp>
#include <MainMenuMachine.hpp>

union SDL_Event;
struct SDL_Renderer;

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
