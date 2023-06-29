#include "tetrominoes.h"

Tetromino::Tetromino(const Board &board, const bool *shape, int dimension, Color color)
    : board(board),
      boardPos(board.getWidth() / 2 - dimension / 2, 0),
      shape(shape),
      dimension(dimension),
      color(color)
{
}

void Tetromino::Draw() const
{
    for (int y = 0; y < dimension; ++y)
    {
        for (int x = 0; x < dimension; ++x)
        {
            bool cell = shape[y * dimension + x];

            if (cell)
            {
                board.DrawCell(boardPos + Vec2<int>{x, y}, color);
            }
        }
    }
}
