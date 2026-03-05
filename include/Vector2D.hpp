#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

class Vector2D{
    private:
        float x, y;
    public:
        Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

        float getX() const { return x; }
        float getY() const { return y; }

        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }

        Vector2D add(const Vector2D& other) const {
            return Vector2D(x + other.x, y + other.y);
        }

        Vector2D subtract(const Vector2D& other) const {
            return Vector2D(x - other.x, y - other.y);
        }

        Vector2D multiply(float scalar) const {
            return Vector2D(x * scalar, y * scalar);
        }

        Vector2D divide(float scalar) const {
            return Vector2D(x / scalar, y / scalar);
        }
};

#endif // VECTOR2D_HPP