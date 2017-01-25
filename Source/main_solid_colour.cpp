#include "drawing.h"

extern SDL_Surface *screen;
extern int t;

void Update();

void Draw();


int main(int argc, char *argv[]) {
    screen = InitializeSDL(SCREEN_WIDTH, SCREEN_HEIGHT);
    t = SDL_GetTicks();    // Set start value for timer.

    while (NoQuitMessageSDL()) {
        Update();
        Draw();
    }

    SDL_SaveBMP(screen, "screenshot.bmp");
    return 0;
}

SDL_Surface *screen;
int t;

void Update() {
    // Compute frame time:
    int t2 = SDL_GetTicks();
    float dt = float(t2 - t);
    t = t2;
    cout << "Render time: " << dt << " ms." << endl;
}

void Draw() {
    if (SDL_MUSTLOCK(screen))
        SDL_LockSurface(screen);

    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            vec3 color(0.0, 1.0, 0.0);
            PutPixelSDL(screen, x, y, color);
        }
    }

    if (SDL_MUSTLOCK(screen))
        SDL_UnlockSurface(screen);

    SDL_UpdateRect(screen, 0, 0, 0, 0);
}