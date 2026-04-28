#include <machine.hpp>


namespace {
const auto points = [] () {
    std::array<SDL_FPoint, 1000> points;
    for (int i = 0; i < points.size(); ++i) {
        points[i].x = SDL_randf() * 1024;
        points[i].y = SDL_randf() * 768;
    }
    return points;
} ();
}


auto Machine::processEvent(const SDL_Event& event) -> Transition {
    switch (event.type) {
    case SDL_EVENT_QUIT:
        return Transition::exit;
    case SDL_EVENT_KEY_DOWN:
        if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
            return Transition::exit;
        }
        break;
    }
    return Transition::stay;
}


void Machine::iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_FRect rect{0.5, 0.5, 300, 300};
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderPoints(renderer, points.data(), points.size());

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderLine(renderer, 0, 0, 1024, 768);
    SDL_RenderLine(renderer, 0, 768, 1024, 0);

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderLines(renderer, points.data(), points.size());

    SDL_RenderPresent(renderer);
}


void* toVoidStar(Machine* machine) {
    return static_cast<void*>(machine);
}


Machine* toMachine(void* appState) {
    return static_cast<Machine*>(appState);
}
