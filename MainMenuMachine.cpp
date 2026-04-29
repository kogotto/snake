#include <MainMenuMachine.hpp>

#include <SDL3/SDL.h>


auto MainMenuMachine::processEvent(const SDL_Event& event) -> Transition {
    switch (event.type) {
    case SDL_EVENT_KEY_UP:
        switch (event.key.scancode) {
        case SDL_SCANCODE_Q:
            return Transition::exit;
        case SDL_SCANCODE_RETURN:
            return Transition::startGame;
        default:
            break;
        }
        break;
    }
    return Transition::stay;
}


void MainMenuMachine::iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_FRect rect{0, 0, 300, 300};
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}
