#include "../include/Sprite.h"
#include <iostream>

// Constructor: Initializes the sprite, loads BMP image as texture
Sprite::Sprite(SDL_Renderer* renderer, const std::string& filePath, float x, float y, float speed)
    : mRenderer(renderer), mSpeed(speed), xPositiveDirection(true), yPositiveDirection(true), mTexture(nullptr) {

    // ✅ Combine base path with the provided filename
    std::string fullPath = "C:/Users/93135/source/repos/assignment-04-IanZuo/Assignment/Assets/" + filePath;

    // Debugging: Print the actual file path being used
    std::cout << "Loading sprite from: " << fullPath << std::endl;

    // Set sprite position and size
    mSprite.x = x;
    mSprite.y = y;
    mSprite.w = 40.0f;
    mSprite.h = 40.0f;

    // Load BMP file
    SDL_Surface* surface = SDL_LoadBMP(fullPath.c_str());
    if (!surface) {
        std::cerr << "Failed to load BMP: " << SDL_GetError() << " (Path: " << fullPath << ")" << std::endl;
        return;
    }

    // Convert surface to texture
    mTexture = SDL_CreateTextureFromSurface(mRenderer, surface);
    SDL_FreeSurface(surface);

    if (!mTexture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    }
}

// Destructor: Cleans up resources
Sprite::~Sprite() {
    if (mTexture) {
        SDL_DestroyTexture(mTexture);
    }
}

// Moves sprite based on direction and speed
void Sprite::Update(float deltaTime) {
    float movement = mSpeed * deltaTime;

    // Move in X direction
    if (xPositiveDirection) mSprite.x += movement;
    else mSprite.x -= movement;

    // Move in Y direction
    if (yPositiveDirection) mSprite.y += movement;
    else mSprite.y -= movement;

    // Check for collisions with screen edges (800x600 window)
    if (mSprite.x <= 0 || mSprite.x + mSprite.w >= 800) {
        xPositiveDirection = !xPositiveDirection;
        mSprite.x = std::max(0.0f, std::min(mSprite.x, 800.0f - mSprite.w));
    }

    if (mSprite.y <= 0 || mSprite.y + mSprite.h >= 600) {
        yPositiveDirection = !yPositiveDirection;
        mSprite.y = std::max(0.0f, std::min(mSprite.y, 600.0f - mSprite.h));
    }
}

// Render: Draws sprite to screen
void Sprite::Render() {
    if (mTexture) {
        SDL_RenderCopyF(mRenderer, mTexture, nullptr, &mSprite);
    }
}
