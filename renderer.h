#ifndef RENDERER_H
#define RENDERER_H

#include "types.h"
#include <SDL3/SDL.h>
#include <vector>
#include <cmath>
#include <chrono>

class Renderer {
    public:
        Renderer(SDL_Window* window, SDL_Renderer* renderer, std::vector<Point3D>& points, std::vector<Edge>& edges);
        void render();

    private:
        int windowWidth;
        int windowHeight;

        float rotation = 0.0f;
        float focalLength = 10.0f;
        float deltaTime = 0.0f;

        SDL_Renderer* renderer;
        std::vector<Point3D> points;
        std::vector<Edge> edges;
};

#endif
