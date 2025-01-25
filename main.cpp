#include <iostream>
#include <vector>
#include <SDL3/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Temp", WIDTH, HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    if (NULL == window) {
        std::cout << "Could not create window: " << SDL_GetError << std::endl;
    }

    SDL_Event windowEvent;
    
    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_EVENT_QUIT == windowEvent.type) {
                break;
            }
        }

        
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
