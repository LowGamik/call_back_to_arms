#ifndef ENGINE_HPP
#define ENGINE_HPP

#include<SDL3/SDL.h>
#include<vector>
#include<memory>

#include "GameObject.hpp"

class Engine{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        bool isRunning;
        std::vector<std::unique_ptr<GameObject>> gameObjects;
    public:
        Engine();

        bool init(const char* title, int width, int height);
        void run();
        void cleanup();

        void addGameObject(std::unique_ptr<GameObject> obj);

        ~Engine();
};

#endif // ENGINE_HPP