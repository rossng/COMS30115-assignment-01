#include "drawing.h"

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

void Interpolate(float a, float b, vector<float> &result) {
    unsigned long size = result.size();

    if (size == 1) {
        result[0] = (a+b)/2.0f;
    } else {
        float step = (b-a)/(size-1);
        for (int i = 0; i < result.size(); i++) {
            result[i] = a + i * step;
        }
    }
}