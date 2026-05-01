#include <GameModel.hpp>


GameModel::GameModel() {
    // snake body
    field_.cell({24, 29}) = Cell::bodyRight;
    field_.cell({24, 30}) = Cell::bodyRight;
    field_.cell({24, 31}) = Cell::bodyRight;
    field_.cell({24, 32}) = Cell::bodyRight;

    // food
    field_.cell({24, 60}) = Cell::food;
    field_.cell({12, 11}) = Cell::food;
    field_.cell({40, 25}) = Cell::food;
}


void GameModel::update() {

}
