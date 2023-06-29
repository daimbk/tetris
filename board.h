#pragma once
#include "raylibWrappers.h"
#include <vector>
#include "vector2.h"

class Board
{
private:
    class Cell
    {
    private:
        bool bExists;
        Color color; // raylib color class

    public:
        Cell();

        void setColor(Color color_input);
        Color getColor() const;
        void Remove();
        bool Exists() const;
    };

public:
    Board(Vec2<int> screenPosition, Vec2<int> widthHeight, int cellSize, int padding);

    void SetCell(Vec2<int> position, Color color);
    void DrawCell(Vec2<int> pos) const;
    void DrawCell(Vec2<int> pos, Color color) const;
    void DrawBorder() const;
    void Draw() const;
    bool CellExists(Vec2<int> pos) const;
    int getWidth() const;
    int getHeight() const;

private:
    std::vector<Cell> cells;
    Vec2<int> screenPosition;
    const int width;
    const int height;
    const int cellSize;
    const int padding;
};
