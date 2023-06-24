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

    constexpr Vec2(T x, T y)
        : x(x),
          y(y)
    {
    }

    // getters/setters
    constexpr T getX() const { return x; }
    constexpr T getY() const { return y; }
    constexpr void setX(T x_input) { x = x_input; };
    constexpr void setY(T y_input) { y = y_input; };

public:
    // operator overloading
    constexpr bool operator==(const Vec2 &rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }

    constexpr bool operator!=(const Vec2 &rhs) const
    {
        return !(*this == rhs);
    }

    constexpr Vec2 operator+(const Vec2 &rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }

    constexpr Vec2 operator+(const int rhs) const
    {
        return {x + rhs, y + rhs};
    }

    constexpr Vec2 operator-(const Vec2 &rhs) const
    {
        return {x - rhs.x, y - rhs.y};
    }

    constexpr Vec2 operator-(const int rhs) const
    {
        return {x - rhs, y - rhs};
    }

    constexpr Vec2 operator*(const Vec2 &rhs) const
    {
        return {x * rhs.x, y * rhs.y};
    }

    constexpr Vec2 operator*(const int rhs) const
    {
        return {x * rhs, y * rhs};
    }

    constexpr Vec2 operator*=(const Vec2 &rhs)
    {
        return *this = *this * rhs;
    }

    constexpr Vec2 &operator+=(const Vec2 &rhs)
    {
        return *this = *this + rhs;
    }

    constexpr Vec2 &operator-=(const Vec2 &rhs)
    {
        return *this = *this - rhs;
    }
};
