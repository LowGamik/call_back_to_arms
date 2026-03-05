#include <iostream>

#include "Engine.hpp"

Engine::Engine() : window(nullptr), renderer(nullptr) {}

bool Engine::init(const char* title, int width, int height) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, width, height, 0);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    this->gameObjects = std::vector<std::unique_ptr<GameObject>>();

    isRunning = true;

    return true;
}

void Engine::run(){
    uint32_t firstTimestamp = SDL_GetTicks();
    uint32_t currentTimestamp = firstTimestamp;
    float deltaTime = 0.0f;

    for(auto &obj : gameObjects) {
        obj->init();
    }

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            currentTimestamp = SDL_GetTicks();
            deltaTime = (currentTimestamp - firstTimestamp) / 1000.0f;

            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }

        for(auto &obj : gameObjects) {
            if(!obj->update(deltaTime)) {
                isRunning = false; // in case of needed to stop when certain object condition is met (like hp <= 0)
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        for(auto &obj : gameObjects) {
            obj->render();
        }
    }
}

void Engine::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

void Engine::addGameObject(std::unique_ptr<GameObject> obj) {
    gameObjects.push_back(std::move(obj));
}

Engine::~Engine() {
    cleanup();
}