#include <GameView.hpp>

#include <array>

#include <SDL3/SDL.h>


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


void GameView::draw(SDL_Renderer* renderer,
                    const GameModel& model) const {

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderPoints(renderer, points.data(), points.size());

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderLine(renderer, 0, 0, 1024, 768);
    SDL_RenderLine(renderer, 0, 768, 1024, 0);

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderLines(renderer, points.data(), points.size());

    SDL_RenderPresent(renderer);
}
