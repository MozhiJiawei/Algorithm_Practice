//input: 0 <= N <= 10^18
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double N, sum = 1, number;
    double lower, higher;
    double width, position;
    cin >> N;
    for (double i = 1; i < 30; i++) {
        lower = pow(10, i - 1);
        higher = pow(10, i);
        sum += (higher - lower) * i;
        if ((sum - N) > 0.000001) {
            width = i;
            break;
        }
    }
    lower = pow(10, width - 1);
    higher = pow(10, width);
    sum -= (higher - lower) * width;
    N = N - sum;
    number = floor(N / width) + lower;
    double b;
    b = N / width;
    position = floor((N / width - floor(N / width)) * width);
    double a;
    a = floor(number / pow(10, width - position)) * pow(10, width - position);
    cout << int(floor((number - a) / pow(10, width - position - 1))) << endl;
    return 0;
}