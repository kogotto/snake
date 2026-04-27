#include <SDL3/SDL.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

SDL_AppResult SDL_AppInit(void** gameState, int argc, char** argv) {
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* gameState, SDL_Event* event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* gameState) {
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* gameState, SDL_AppResult result) {

}
