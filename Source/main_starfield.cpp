#include "drawing.h"

SDL_Surface *screen;
int t;
const float v = 0.001;

void Update(vector<vec3>& stars);

void Draw(vector<vec3>& stars);

vector<vec3> GenerateStars(int num);


int main(int argc, char *argv[]) {
    screen = InitializeSDL(SCREEN_WIDTH, SCREEN_HEIGHT);
    t = SDL_GetTicks();    // Set start value for timer.

    vector<vec3> stars = GenerateStars(1000);

    while (NoQuitMessageSDL()) {
        Draw(stars);
        Update(stars);
    }

    SDL_SaveBMP(screen, "screenshot.bmp");
    return 0;
}

void Update(vector<vec3>& stars) {
    // Compute frame time:
    int t2 = SDL_GetTicks();
    float dt = float(t2 - t);
    t = t2;
    cout << "Render time: " << dt << " ms." << endl;

    for (int i = 0; i < stars.size(); i++) {
        stars[i].z -= v * dt;
        if (stars[i].z <= 0) {
            stars[i].z += 1;
        }
        if (stars[i].z > 1) {
            stars[i].z -= 1;
        }
    }
}

/**
 * @return a vector of 1000 random stars. vec3(-1 <= x <= 1, -1 <= y <= 1, 0 < z <= 1)
 */
vector<vec3> GenerateStars(int num) {
    vector<vec3> stars;
    for (int i = 0; i < num; i++) {
        float x = float(rand()) / float(RAND_MAX);
        float y = float(rand()) / float(RAND_MAX);
        float z = float(rand()) / float(RAND_MAX);
        stars.push_back(vec3(x*2-1, y*2-1, z));
    }
    return stars;
}

void Draw(vector<vec3>& stars) {
    if (SDL_MUSTLOCK(screen))
        SDL_LockSurface(screen);

    SDL_FillRect(screen, 0, 0);

    float focal_length = SCREEN_WIDTH / 2.0f;
    for (auto star : stars) {
        float u = focal_length * (star.x / star.z) + (SCREEN_WIDTH / 2.0f);
        float v = focal_length * (star.y / star.z) + (SCREEN_HEIGHT / 2.0f);
        vec3 colour = 0.2f * vec3(1, 1, 1) / (star.z * star.z);

        PutPixelSDL(screen, (int)u, (int)v, colour);
    }

    if (SDL_MUSTLOCK(screen))
        SDL_UnlockSurface(screen);

    SDL_UpdateRect(screen, 0, 0, 0, 0);
}