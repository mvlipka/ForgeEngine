#ifndef FORGEENGINE_VECTOR2D_H
#define FORGEENGINE_VECTOR2D_H

#include <iostream>
#include <cmath>


class Vector2D {
public:
    float x, y;

    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D &v) const {
        return {x + v.x, y + v.y};
    }

    Vector2D operator-(const Vector2D &v) const {
        return {x - v.x, y - v.y};
    }

    Vector2D operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    float dot(const Vector2D &v) const {
        return x * v.x + y * v.y;
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2D &normalize() {
        float mag = magnitude();
        if (mag > 0) {
            x /= mag;
            y /= mag;
        }
        return *this;
    }

    void print() const {
        std::cout << "Vector(" << x << ", " << y << ")" << std::endl;
    }
};


#endif //FORGEENGINE_VECTOR2D_H
