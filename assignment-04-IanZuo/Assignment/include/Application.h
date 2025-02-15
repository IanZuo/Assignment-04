#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Sprite.h"

class Application {
public:
    Application();
    ~Application();
    bool Initialize();
    void Run(int targetFPS);
    void Shutdown();

private:
    void ProcessInput();
    void Update(float deltaTime);
    void Render();

    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    bool mRun;
    std::vector<std::unique_ptr<Sprite>> mEnemies;
    std::unique_ptr<Sprite> mainCharacter;
};

#endif

