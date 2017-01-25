#include "drawing.h"
#include "glm/gtc/epsilon.hpp"


#define EPSILON 0.00000001

bool float_equals(float a, float b);
bool Interpolate_test1();
bool Interpolate_test2();
bool Interpolate_test3();

int main(int argc, char *argv[]) {
    vector<bool> results;
    results.push_back(Interpolate_test1());
    results.push_back(Interpolate_test2());
    results.push_back(Interpolate_test3());

    for (int i = 0; i < results.size(); i++) {
        cout << "Test " << i+1 << ": " << (results[i] ? "PASS" : "FAIL") << endl;
    }
}

bool Interpolate_test1() {
    bool passed = true;
    vector<float> expected = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    vector<float> result(10);
    Interpolate(5, 14, result);
    for (int i = 0; i < expected.size(); i++) {
        passed &= float_equals(expected[i], result[i]);
    }
    return passed;
}

bool Interpolate_test2() {
    bool passed = true;
    vector<float> expected = { 9.5 };
    vector<float> result(1);
    Interpolate(9, 10, result);
    for (int i = 0; i < expected.size(); i++) {
        passed &= float_equals(expected[i], result[i]);
    }
    return passed;
}

bool Interpolate_test3() {
    bool passed = true;
    vector<vec3> expected = { vec3(1, 4, 9.2), vec3(2, 3, 9.4), vec3(3, 2, 9.6), vec3(4, 1, 9.8) };
    vector<vec3> result(4);
    Interpolate(vec3(1, 4, 9.2), vec3(4, 1, 9.8), result);
    for (int i = 0; i < expected.size(); i++) {
        passed &= glm::all(glm::epsilonEqual(expected[i], result[i], vec3(EPSILON, EPSILON, EPSILON)));
        //cout << "Passed: " << passed << ". result[" << i << "] = (" << result[i].x << "," << result[i].y << "," << result[i].z << ")" << endl;
    }
    return passed;
}

bool float_equals(float a, float b) {
    return abs(a - b) < EPSILON;
}