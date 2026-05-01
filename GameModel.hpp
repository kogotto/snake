#pragma once

#include <Field.hpp>

enum class Cell {
    empty,
    bodyUp,
    bodyRight,
    bodyDown,
    bodyLeft,
    food,

    count
};

class GameModel {
public:
    using FieldType = Field<Cell>;

    GameModel();

    const FieldType& getField() const {
        return field_;
    }

    void update();
private:
    FieldType field_{48, 64};
};
