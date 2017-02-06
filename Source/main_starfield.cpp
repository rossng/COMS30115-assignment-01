#include "drawing.h"

SDL_Surface *screen;
int t;
const float v = 0.0005;

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

    glm::vec3 camera_position = glm::vec3(0.0f, 1.1f, 0.5f);

    glm::mat4 projection = glm::perspective(glm::radians(90.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(camera_position, glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f));
#ifdef DEBUG
    std::cout << glm::to_string(projection) << std::endl;
    std::cout << glm::to_string(view) << std::endl;
#endif

    for (auto star : stars) {
        glm::mat4 model = glm::translate(glm::mat4(1.0), star);
        glm::mat4 mvp = projection * view * model;
        glm::vec4 position = mvp * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        vec3 colour = vec3(1.0f, 1.0f, 1.0f) / (1.0f + glm::distance(camera_position, star) * glm::distance(camera_position, star));

        float u = (SCREEN_WIDTH / 2.0f) * (1 - position.x);
        float v = (SCREEN_HEIGHT / 2.0f) * (1 - position.y);

        PutPixelSDL(screen, (int)u, (int)v, colour);
#ifdef DEBUG
        std::cout << glm::to_string(model) << std::endl;
        std::cout << glm::to_string(mvp) << std::endl;
        std::cout << glm::to_string(position) << std::endl;
#endif
    }

    if (SDL_MUSTLOCK(screen))
        SDL_UnlockSurface(screen);

    SDL_UpdateRect(screen, 0, 0, 0, 0);
}