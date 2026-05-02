#include <GameMachine.hpp>

#include <SDL3/SDL.h>


auto GameMachine::processEvent(const SDL_Event& event) -> Transition {
    switch (event.type) {
    case SDL_EVENT_KEY_DOWN:
        switch (event.key.scancode) {
        case SDL_SCANCODE_ESCAPE:
            return Transition::exit;
        case SDL_SCANCODE_UP:
            model.setCurrentDirection(dirs::up);
            break;
        case SDL_SCANCODE_RIGHT:
            model.setCurrentDirection(dirs::right);
            break;
        case SDL_SCANCODE_DOWN:
            model.setCurrentDirection(dirs::down);
            break;
        case SDL_SCANCODE_LEFT:
            model.setCurrentDirection(dirs::left);
            break;
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
