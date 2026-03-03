// START OF FILE

// DEFINES
#define SDL_MAIN_HANDLED

// INCLUDES
#include<iostream>
#include<memory>
#include "Engine.hpp"

// DECLARATIONS

// MAIN
int main(){
    auto engine = std::make_unique<Engine>();

    if(!engine->init("SDL3 Engine", 800, 600)) {
        std::cerr << "Failed to initialize the engine!" << std::endl;
        return -1;
    }

    engine->run();

    return 0;
}

// FUNCTION DEFINITIONS

// END OF FILE