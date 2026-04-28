#include <array>

#include <SDL3/SDL.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

#include <machine.hpp>

namespace {
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
}

SDL_AppResult SDL_AppInit(void** appState, int argc, char** argv) {
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

    *appState = toVoidStar(new Machine{});

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appState, SDL_Event* event) {
    auto& machine = *toMachine(appState);
    if (machine.processEvent(*event) == Machine::Transition::exit) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appState) {
    auto& machine = *toMachine(appState);
    machine.iterate(renderer, std::chrono::milliseconds{SDL_GetTicks()});

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appState, SDL_AppResult result) {
    delete toMachine(appState);
}
