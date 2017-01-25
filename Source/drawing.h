//
// Created by ross on 25/01/17.
//

#ifndef PROJECT_DRAWING_CPP_H
#define PROJECT_DRAWING_CPP_H

#include <iostream>
#include <glm/glm.hpp>
#include <SDL/SDL.h>
#include "SDLauxiliary.h"
#include "TestModel.h"

using namespace std;
using glm::vec3;
using glm::mat3;

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
extern SDL_Surface *screen;
extern int t;

void Update();

void Draw();

void Interpolate(float a, float b, vector<float> &result);

#endif //PROJECT_DRAWING_CPP_H
