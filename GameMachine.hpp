#pragma once

#include <chrono>

#include <GameModel.hpp>
#include <GameView.hpp>
#include <Timer.hpp>

union SDL_Event;
struct SDL_Renderer;

class GameMachine {
public:
    enum class Transition {
        stay,
        exit,
    };

    Transition processEvent(const SDL_Event& event);
    void iterate(SDL_Renderer* renderer, std::chrono::milliseconds tick);
private:
    GameModel model;
    GameView view;
    Timer timer{std::chrono::milliseconds{0},
        std::chrono::milliseconds{1000}};
};
