#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Vector2D.hpp"

class GameObject{
    private:
        Vector2D position;
        Vector2D velocity;
        bool isActive = true;
    public:
        GameObject(const Vector2D& position = Vector2D(), const Vector2D& velocity = Vector2D())
            : position(position), velocity(velocity) {}

        Vector2D getPosition() const { return position; }
        Vector2D getVelocity() const { return velocity; }

        void setPosition(const Vector2D& position) { this->position = position; }
        void setVelocity(const Vector2D& velocity) { this->velocity = velocity; }

        virtual bool init() = 0;
        virtual bool update(float dt) = 0;
        virtual void render() = 0;
};

#endif // GAMEOBJECT_HPP