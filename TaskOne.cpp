#include <iostream>
#include "math.h"
#include "vector"

using namespace std;

double funOne(double x) {
    return -x*x + 4*x;
}

vector<int> funOne() {
    return {-1, 4, 0};
}

double funTwo(double x) {
    return -1*x + 4;
}

vector<int> funTwo() {
    return {0, -1, 4};
}

vector<int>  getIndexesResultFun(vector<int> fun1, vector<int> fun2) {
    vector<int> indexes = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        indexes[i] = fun1[i] - fun2[i];
    }

    return indexes;
}

vector<int> findIntersectionPoints(vector<int> fun1, vector<int> fun2) {
    vector<int> indexes = getIndexesResultFun(fun1, fun2);

    int d = indexes[1]*indexes[1] - 4*(indexes[0]*indexes[2]);
    vector<int> v;
    v.push_back((-indexes[1] + sqrt(d)) / 2*indexes[0]);
    v.push_back((-indexes[1] - sqrt(d)) / 2*indexes[0]);

    return v;
}

int findIntersectionPoints(vector<int> fun) {
    return fun[2];
}

double getIntegral(double(*func)(double), int a, int b) {
    double sum = 0;
    double i = a;
    double step = pow(10, -8);

    while (i <=  b) {
        sum += ((func(i) + func(i + step)) / 2 * step);
        i += step;
    }

    return sum;
}

int main() {
    vector<int> interval = findIntersectionPoints(funOne(), funTwo());

    cout << getIntegral(funOne, interval[0], interval[1]) - getIntegral(funTwo, interval[0], interval[1]);

    return 0;
}
