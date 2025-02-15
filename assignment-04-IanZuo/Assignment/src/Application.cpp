#include "../include/Application.h"
#include <iostream>

Application::Application() : mWindow(nullptr), mRenderer(nullptr), mRun(true) {}

Application::~Application() {
    Shutdown();
}

bool Application::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Init Failed: " << SDL_GetError() << std::endl;
        return false;
    }
    
    mWindow = SDL_CreateWindow("Assignment 04", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!mWindow || !mRenderer) return false;
// make Sprite and set speed etc
    mainCharacter = std::make_unique<Sprite>(mRenderer, "Assignment/Assets/Spaceship.bmp", 400, 500, 3000.0f); // ✅ Faster speed
    for (int i = 0; i < 30; ++i) {
        float x = rand() % 760;
        float y = rand() % 560;
        float speed = 50.0f + (rand() % 100); // ✅ Random speed for variety
        mEnemies.push_back(std::make_unique<Sprite>(mRenderer, "Assignment/Assets/Alien.bmp", x, y, 3000.0f));
    }    
    return true;
}

void Application::Run(int targetFPS) {
    const int frameDelay = 1000 / targetFPS;
    Uint32 frameStart, frameTime;
    float deltaTime = 0.0f;
    int frameCount = 0;
    Uint32 startTime = SDL_GetTicks(); // Track time for FPS

    while (mRun) {
        frameStart = SDL_GetTicks();
        ProcessInput();

        //calculate delta time
        deltaTime = (SDL_GetTicks() - frameStart) / 1000.0f;
        Update(deltaTime);
        Render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);

        //FPS Calculation
        frameCount++;
        if (SDL_GetTicks() - startTime >= 1000) { // Every second
            int fps = frameCount;
            frameCount = 0;
            startTime = SDL_GetTicks();

            //Update window title with FPS
            std::string title = "Assignment 04 - FPS: " + std::to_string(fps);
            SDL_SetWindowTitle(mWindow, title.c_str());
        }
    }
}



void Application::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            mRun = false;
        }
    }
}

void Application::Update(float deltaTime) {
    if (mainCharacter) mainCharacter->Update(deltaTime);
    for (auto& enemy : mEnemies) {
        enemy->Update(deltaTime);
    }
}

void Application::Render() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
    
    if (mainCharacter) mainCharacter->Render();
    for (auto& enemy : mEnemies) {
        enemy->Render();
    }
    
    SDL_RenderPresent(mRenderer);
}

void Application::Shutdown() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

