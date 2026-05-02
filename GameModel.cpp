#include <GameModel.hpp>

#include <cassert>


bool isBody(Cell cell) {
    switch (cell) {
    case Cell::bodyUp: [[fallthrough]];
    case Cell::bodyRight: [[fallthrough]];
    case Cell::bodyDown: [[fallthrough]];
    case Cell::bodyLeft:
        return true;
    default:
        return false;
    }
}


Cell toEnum(CellIndex dir) {
    if (dir == dirs::up) {
        return Cell::bodyUp;
    }
    if (dir == dirs::right) {
        return Cell::bodyRight;
    }
    if (dir == dirs::down) {
        return Cell::bodyDown;
    }
    if (dir == dirs::left) {
        return Cell::bodyLeft;
    }

    assert(false && "dir is not from dirs::");
    return Cell::empty;
}


CellIndex toDir(Cell cell) {
    assert(isBody(cell) && "Cell is not from body*");
    switch (cell) {
    case Cell::bodyUp: return dirs::up;
    case Cell::bodyRight: return dirs::right;
    case Cell::bodyDown: return dirs::down;
    case Cell::bodyLeft: return dirs::left;
    default: ; // unreachable due to assert
    }
    return dirs::up;
}


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


void GameModel::setCurrentDirection(CellIndex newDir) {
    if (currentDirection_ == -newDir) {
        return;
    }
    currentDirection_ = newDir;
}


void GameModel::update() {
    for (const auto index : field_.indexRange()) {
        if (isHead(index)) {
            updateHead(index);
            break;
        }
    }
    for (const auto index : field_.indexRange()) {
        if (isTail(index)) {
            updateTail(index);
            break;
        }
    }
}


bool GameModel::isHead(CellIndex index) const {
    const Cell cell = field_.cell(index);
    if (!isBody(cell)) {
        return false;
    }
    const CellIndex nextCellIndex = index + toDir(cell);
    return !isBody(field_.cell(nextCellIndex));
}


void GameModel::updateHead(NormalizedIndex index) {
    Cell& head = field_.cell(index);
    head = toEnum(currentDirection_);
    auto newHeadIndex = index + currentDirection_;
    field_.cell(newHeadIndex) = head;
}


bool GameModel::isTail(CellIndex index) const {
    const Cell cell = field_.cell(index);
    return isBody(cell) && !hasBodyBefore(index);
}


bool GameModel::hasBodyBefore(CellIndex index) const {
    auto allDirs = {dirs::up, dirs::right, dirs::down, dirs::left};
    const Cell cell = field_.cell(index);
    const CellIndex cellDir = toDir(cell);
    for (const auto dir : allDirs) {
        if (dir == cellDir) {
            continue;
        }
        const CellIndex prevCellIndex = index + dir;
        const Cell prevCell = field_.cell(prevCellIndex);
        if (!isBody(prevCell)) {
            continue;
        }
        const CellIndex prevCellDir = toDir(prevCell);
        if (prevCellIndex + prevCellDir == index) {
            return true;
        }
    }
    return false;
}


void GameModel::updateTail(CellIndex index) {
    field_.cell(index) = Cell::empty;
}
