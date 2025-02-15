#define SDL_MAIN_HANDLED
#include "../include/Application.h"
#include <SDL2/SDL.h>

int main() {
    Application app;
    if (!app.Initialize()) {
        return -1;
    }
    app.Run(60);
    return 0;
}
