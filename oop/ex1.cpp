//Даны два действительных числа a и b. Получить их сумму, разность и произведение.
//
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>
using namespace std;
float sum(float a, float b)
{
    return a + b;
}
float diff(float a, float b)
{
    return a - b;
}
float mul(float a, float b)
{
    return a * b;
}
int main()
{
    assert(fabs(sum(4, 3) - 7) < FLT_EPSILON);
    assert(fabs(sum(4, 4) - 8) < FLT_EPSILON);
    assert(fabs(sum(3, 3) - 6) < FLT_EPSILON);
    assert(fabs(diff(4, 3) - 1) < FLT_EPSILON);
    assert(fabs(diff(7, 3) - 4) < FLT_EPSILON);
    assert(fabs(diff(4, 2) - 2) < FLT_EPSILON);
    assert(fabs(mul(4, 3) - 12) < FLT_EPSILON);
    assert(fabs(mul(4, 7) - 28) < FLT_EPSILON);
    assert(fabs(mul(4, 5) - 20) < FLT_EPSILON);
    float a, b;
    cout << "enter a: ";
    cin >> a;
    cout << "enter b: ";
    cin >> b;
    sum(a, b);
    diff(a, b);
    mul(a, b);
    cout << "summa: " << sum(a, b) << "\n";
    cout << "diff:" << diff(a, b) << "\n";
    cout << "multiplication: " << mul(a, b) << "\n";

}