#pragma once

struct SDL_Renderer;

class GameModel;

class GameView {
public:
    void draw(SDL_Renderer* renderer, const GameModel& model) const;
private:
};
