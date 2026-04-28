#include <array>

#include <SDL3/SDL.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

namespace {
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
const auto points = [] () {
    std::array<SDL_FPoint, 1000> points;
    for (int i = 0; i < points.size(); ++i) {
        points[i].x = SDL_randf() * 1024;
        points[i].y = SDL_randf() * 768;
    }
    return points;
} ();
}

SDL_AppResult SDL_AppInit(void** gameState, int argc, char** argv) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer(
                "snake by kogo",
                1024, 768,
                0,
                &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(
            renderer,
            1024, 768,
            SDL_LOGICAL_PRESENTATION_LETTERBOX);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* gameState, SDL_Event* event) {
    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    case SDL_EVENT_KEY_DOWN:
        if (event->key.scancode == SDL_SCANCODE_ESCAPE) {
            return SDL_APP_SUCCESS;
        }
        break;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* gameState) {
    const auto ticks = SDL_GetTicksNS();
    SDL_Log("Elapsed: %ldms", ticks);

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

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* gameState, SDL_AppResult result) {

}
