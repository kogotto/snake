#pragma once

#include <SDL3/SDL.h>

#include <Field.hpp>
#include <GameModel.hpp>

class CellView {
public:
    void setRect(float left, float top, float width, float height);
    void draw(SDL_Renderer* renderer, Cell cell) const;
private:
    SDL_FRect rect_;
};

class GameView {
public:
    using FieldType = Field<CellView>;

    GameView();

    void draw(SDL_Renderer* renderer,
              const GameModel& model) const;
private:
    FieldType field_{48, 64};
};
