#include <GameModel.hpp>


GameModel::GameModel() {
    field_.cell({24, 29}) = Cell::bodyRight;
    field_.cell({24, 30}) = Cell::bodyRight;
    field_.cell({24, 31}) = Cell::bodyRight;
    field_.cell({24, 32}) = Cell::bodyRight;
}


void GameModel::update() {

}
