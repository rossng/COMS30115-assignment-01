#include "drawing.h"


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

void Interpolate(vec3 a, vec3 b, vector<vec3> &result) {
    unsigned long size = result.size();

    if (size == 1) {
        result[0] = (a + b) / 2.0f;
    } else {
        vec3 step = (b - a) / (float)(size-1);
        //cout << "step: (" << step.x << "," << step.y << "," << step.z << ")" << endl;
        for (int i = 0; i < result.size(); i++) {
            result[i] = a + (step * (float)i);
        }
    }

}