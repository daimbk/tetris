#pragma once

// user defined vector class for cleaner code
template <typename T>
class Vec2
{
private:
    T x;
    T y;

public:
    Vec2() = default; // for empty vector

    Vec2(T x, T y)
        : x(x),
          y(y)
    {
    }

    // getters/setters
    T getX() const { return x; }
    T getY() const { return y; }
    void setX(T x_input) { x = x_input; };
    void setY(T y_input) { y = y_input; };

public:
    // operator overloading
    bool operator==(const Vec2 &rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }

    bool operator!=(const Vec2 &rhs) const
    {
        return !(*this == rhs);
    }

    Vec2 operator+(const Vec2 &rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }

    Vec2 operator+(const int rhs) const
    {
        return {x + rhs, y + rhs};
    }

    Vec2 operator-(const Vec2 &rhs) const
    {
        return {x - rhs.x, y - rhs.y};
    }

    Vec2 operator-(const int rhs) const
    {
        return {x - rhs, y - rhs};
    }

    Vec2 operator*(const Vec2 &rhs) const
    {
        return {x * rhs.x, y * rhs.y};
    }

    Vec2 operator*(const int rhs) const
    {
        return {x * rhs, y * rhs};
    }

    Vec2 operator*=(const Vec2 &rhs)
    {
        return *this = *this * rhs;
    }

    Vec2 &operator+=(const Vec2 &rhs)
    {
        return *this = *this + rhs;
    }

    Vec2 &operator-=(const Vec2 &rhs)
    {
        return *this = *this - rhs;
    }
};
