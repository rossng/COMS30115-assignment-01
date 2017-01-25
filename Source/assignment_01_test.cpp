#include "drawing.h"

bool float_equals(float a, float b);
int Interpolate_test1();
int Interpolate_test2();

int main(int argc, char *argv[]) {
    Interpolate_test1();
    Interpolate_test2();
}

int Interpolate_test1() {
    bool passed = true;
    vector<float> expected = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    vector<float> result(10);
    Interpolate(5, 14, result);
    for (int i = 0; i < expected.size(); i++) {
        if (!float_equals(expected[i], result[i])) {
            passed = false;
        }
    }
    cout << "Test 1: " << (passed ? "PASS" : "FAIL") << endl;
}

int Interpolate_test2() {
    bool passed = true;
    vector<float> expected = { 9.5 };
    vector<float> result(1);
    Interpolate(9, 10, result);
    for (int i = 0; i < expected.size(); i++) {
        if (!float_equals(expected[i], result[i])) {
            passed = false;
        }
    }
    cout << "Test 2: " << (passed ? "PASS" : "FAIL") << endl;
}

bool float_equals(float a, float b) {
    return abs(a - b) < 0.00000001;
}