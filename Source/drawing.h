//
// Created by ross on 25/01/17.
//

#ifndef PROJECT_DRAWING_CPP_H
#define PROJECT_DRAWING_CPP_H

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <SDL/SDL.h>
#include <unistd.h>
#include "SDLauxiliary.h"
#include "TestModel.h"

using namespace std;
using glm::vec3;
using glm::mat3;

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
void Interpolate(float a, float b, vector<float> &result);

void Interpolate(vec3 a, vec3 b, vector<vec3> &result);

#endif //PROJECT_DRAWING_CPP_H
