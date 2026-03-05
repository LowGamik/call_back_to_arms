#ifndef SCENE_HPP
#define SCENE_HPP

#include "GameObject.hpp"
#include<vector>
#include<memory>

class Scene{
    private:
        std::vector<std::unique_ptr<GameObject>> gameObjects;
        bool isActive = true;
    public:
        Scene();
};

#endif // SCENE_HPP