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

namespace dirs {
constexpr CellIndex up    {RowIndex{-1}, ColIndex{0}};
constexpr CellIndex right {RowIndex{0}, ColIndex{1}};
constexpr CellIndex down  {RowIndex{1}, ColIndex{0}};
constexpr CellIndex left  {RowIndex{0}, ColIndex{-1}};
} // namespace dirs

[[nodiscard]] bool isBody(Cell cell);
[[nodiscard]] Cell toEnum(CellIndex dir);
[[nodiscard]] CellIndex toDir(Cell);

class GameModel {
public:
    using FieldType = Field<Cell>;

    GameModel();

    const FieldType& getField() const {
        return field_;
    }

    void update();
private:
    bool isHead(CellIndex index) const;

    void updateHead(NormalizedIndex index);

    FieldType field_{48, 64};
    CellIndex currentDirection_{dirs::right};
};
