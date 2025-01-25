#include "renderer.h"

Point3D rotate(Point3D point, float rotation) {
    return rotateX(rotateY(point, rotation), rotation);
}

Renderer::Renderer(SDL_Window* window, SDL_Renderer* renderer, std::vector<Point3D>& points, std::vector<Edge>& edges) : renderer(renderer), points(points), edges(edges) {
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
}

void Renderer::render() {
    auto timeStart = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration(0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // set drawing colour to black
    SDL_RenderClear(renderer); // fill with black
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // set drawing  colour to white

    rotation += 1 * deltaTime;

    for (Edge& edge : edges) {
        Point3D newStart = rotate(points[edge.start], rotation);
        Point3D newEnd = rotate(points[edge.end], rotation);

        Point2D projectedStart = project(newStart, focalLength, windowWidth, windowHeight);
        Point2D projectedEnd = project(newEnd, focalLength, windowWidth, windowHeight);

        SDL_RenderLine(renderer, projectedStart.x, projectedStart.y, projectedEnd.x, projectedEnd.y);
    }
    SDL_RenderPresent(renderer);

    auto timeEnd = std::chrono::high_resolution_clock::now();
    duration = timeEnd - timeStart;
    deltaTime = duration.count();
    timeStart = timeEnd;
}

