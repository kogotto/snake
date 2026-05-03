#include <Machine.hpp>

#include <SDL3/SDL.h>


auto Machine::processEvent(const SDL_Event& event) -> Transition {
    switch (event.type) {
    case SDL_EVENT_QUIT:
        return Transition::exit;
    }

    switch (current) {
    case State::mainMenu:
        switch (mainMenuMachine.processEvent(event)) {
        case MainMenuMachine::Transition::startGame:
            current = State::game;
            return Transition::stay;
        case MainMenuMachine::Transition::stay:
            return Transition::stay;
        case MainMenuMachine::Transition::exit:
            return Transition::exit;
        }
    case State::game:
        switch (gameMachine.processEvent(event)) {
        case GameMachine::Transition::stay:
            return Transition::stay;
        case GameMachine::Transition::exit:
            current = State::mainMenu;
            return Transition::stay;
        }
    }

    return Transition::stay;
}


void Machine::iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick) {
    switch (current) {
    case State::mainMenu:
        return mainMenuMachine.iterate(renderer, tick);
    case State::game:
        return gameMachine.iterate(renderer, tick);
    }
}


void* toVoidStar(Machine* machine) {
    return static_cast<void*>(machine);
}


Machine* toMachine(void* appState) {
    return static_cast<Machine*>(appState);
}
