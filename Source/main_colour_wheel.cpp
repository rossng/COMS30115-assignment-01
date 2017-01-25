#include "drawing.h"

extern SDL_Surface *screen;
extern int t;

void Update();

void Draw();


int main(int argc, char *argv[]) {
    screen = InitializeSDL(SCREEN_WIDTH, SCREEN_HEIGHT);
    t = SDL_GetTicks();    // Set start value for timer.

    Draw();
    Update();

    while (NoQuitMessageSDL()) {
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

    vec3 top_left(1, 0, 0);         // red
    vec3 top_right(0, 0, 1);        // blue
    vec3 bottom_right(0, 1, 0);     // green
    vec3 bottom_left(1, 1, 0);      // yellow

    vector<vec3> left_side(SCREEN_HEIGHT);
    vector<vec3> right_side(SCREEN_HEIGHT);
    Interpolate(top_left, bottom_left, left_side);
    Interpolate(top_right, bottom_right, right_side);

    vector<vec3> row(SCREEN_WIDTH);
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        Interpolate(left_side[y], right_side[y], row);
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            PutPixelSDL(screen, x, y, row[x]);
        }
    }

    if (SDL_MUSTLOCK(screen))
        SDL_UnlockSurface(screen);

    SDL_UpdateRect(screen, 0, 0, 0, 0);
}