#include <GameMachine.hpp>

#include <SDL3/SDL.h>


auto GameMachine::processEvent(const SDL_Event& event) -> Transition {
    switch (event.type) {
    case SDL_EVENT_KEY_DOWN:
        switch (event.key.scancode) {
        case SDL_SCANCODE_ESCAPE:
            return Transition::exit;
        default:
            break;
        }
        break;
    }
    return Transition::stay;
}

void GameMachine::iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick) {
    if (timer.timeHasCome(tick)) {
        model.update();
    }

    view.draw(renderer, model);
}
