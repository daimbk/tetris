#include "raylibWrappers.h"
#include <assert.h>

void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
    assert(pos.getX() >= 0 && pos.getY() >= 0 &&
           pos.getX() < GetScreenWidth() && pos.getY() < GetScreenHeight()); // triggers: when drawing outside screen
    DrawRectangle(pos.getX(), pos.getY(), widthHeight.getX(), widthHeight.getY(), color);
}

void raycpp::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, int lineThickness, Color color)
{
    assert(pos.getX() >= 0 && pos.getY() >= 0 &&
           pos.getX() < GetScreenWidth() && pos.getY() < GetScreenHeight()); // triggers: when drawing outside screen
    assert(lineThickness > 0);                                               // triggers: line thickness is non existent
    DrawRectangleLinesEx({(float)pos.getX(), (float)pos.getY(), (float)widthHeight.getX(), (float)widthHeight.getY()}, lineThickness, color);
}
