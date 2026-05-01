#include <GameView.hpp>

#include <SDL3/SDL.h>

void CellView::setRect(float left, float top, float width, float height) {
    rect_.x = left;
    rect_.y = top;
    rect_.w = width;
    rect_.h = height;
}


void CellView::draw(SDL_Renderer* renderer, Cell cell) const {
    if (cell == Cell::food) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    }
    SDL_RenderFillRect(renderer, &rect_);
}


GameView::GameView() {
    const auto size = field_.getSize();
    const float stepX = 1024.0 / size.col;
    const float stepY = 768.0 / size.row;
    for (const auto index : field_.indexRange()) {
        field_.cell(index).setRect(index.col * stepX,
                                   index.row * stepY,
                                   stepX, stepY);
    }
}


void GameView::draw(SDL_Renderer* renderer,
                    const GameModel& model) const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    const auto& field = model.getField();
    for (const auto& index : field.indexRange()) {
        const auto& cellModel = field.cell(index);
        if (cellModel == Cell::empty) {
            continue;
        }
        field_.cell(index).draw(renderer, cellModel);
    }

    SDL_RenderPresent(renderer);
}
