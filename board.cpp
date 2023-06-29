#include "board.h"
#include <assert.h>

Board::Cell::Cell()
    : bExists(false),
      color(WHITE)
{
}

void Board::Cell::setColor(Color color_input)
{
    color = color_input;
    bExists = true;
}

Color Board::Cell::getColor() const
{
    return color;
}

void Board::Cell::Remove()
{
    bExists = false;
}

bool Board::Cell::Exists() const
{
    return bExists;
}

Board::Board(Vec2<int> screenPosition, Vec2<int> widthHeight, int cellSize, int padding)
    : screenPosition(screenPosition),
      width(widthHeight.getX()),
      height(widthHeight.getY()),
      cellSize(cellSize),
      padding(padding)
{
    assert(width > 0 && height > 0); // triggers: width or height are less than zero
    assert(cellSize > 0);            // triggers: cell size is less than zero
    cells.resize(width * height);    // constructor called for each cell with resize
}

void Board::SetCell(Vec2<int> pos, Color color)
{
    assert(pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < width && pos.getY() < height); // triggers: x or y are out of bounds
    cells[pos.getY() * width + pos.getX()].setColor(color);
}

void Board::DrawCell(Vec2<int> pos) const
{
    assert(pos.getX() >= 0 && pos.getX() < width && pos.getY() >= 0 && pos.getY() < height); // triggers: x or y are out of bounds
    Color c = cells[pos.getY() * width + pos.getX()].getColor();                             // get color
    Vec2<int> topLeft = screenPosition + padding + (pos * cellSize);
    raycpp::DrawRectangle(topLeft, Vec2<int>{cellSize, cellSize} - padding, c);
}

void Board::DrawBorder() const
{
    raycpp::DrawRectangleLinesEx(screenPosition - (cellSize / 2),
                                 Vec2<int>{width * cellSize, height * cellSize} + cellSize,
                                 cellSize / 2,
                                 WHITE);
}

void Board::Draw() const
{
    for (int iY = 0; iY < height; iY++)
    {
        for (int iX = 0; iX < width; iX++)
        {
            if (CellExists({iX, iY}))
            {
                DrawCell(Vec2<int>{iX, iY});
            }
        }
    }

    DrawBorder();
}

bool Board::CellExists(Vec2<int> pos) const
{
    return cells[pos.getY() * width + pos.getX()].Exists();
}

int Board::getWidth() const
{
    return width;
}

int Board::getHeight() const
{
    return height;
}
