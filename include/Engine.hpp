#ifndef ENGINE_HPP
#define ENGINE_HPP

#include<SDL3/SDL.h>
#include<vector>
#include<memory>

class Engine{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        bool isRunning;
    public:
        Engine();

        bool init(const char* title, int width, int height);
        void run();
        void cleanup();

        ~Engine();
};

#endif // ENGINE_HPP