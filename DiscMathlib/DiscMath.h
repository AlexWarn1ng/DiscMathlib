#pragma once
#include <vector>
#include <utility>

#if defined(_WIN32)
#ifdef DISCMATHLIB_EXPORTS
#define DISCMATH_API __declspec(dllexport)
#else
#define DISCMATH_API __declspec(dllimport)
#endif
#else
#define DISCMATH_API
#endif

DISCMATH_API std::pair<int, int> ExtendedEuclideanAlgorithm(int a, int b); //enter 2 numbers, get two numbers. Just Extended euclidean algorithm
// USE: Enter two numbers, get two numbers.
/*
int main(){
funct(x, y)
answerX = res.first
answerY = res.second
}
*/

DISCMATH_API int FractionalPart(int mk, int dk, int a0, int afirst, std::vector<int>& out); // This function constructs the periodic part of the continued fraction for sqrt(N)
// USE: Example.
/*
int main(){
int m0 = 0, d1 = 1; //For classic tasks, do not recomended to change it
int A;  //The integer part of the square root of your number
int B; //The number under the square root
std::vector<int> vec;
FractionalPart(m0, d1, A, B, vec); // returns in vec, you do not need to make a variable
}
*/

DISCMATH_API std::pair<int, std::pair<double, double>> Approximation(int celoje, std::vector<int>& drobnijoststok, double prib); // It finds the best rational approximation based on an already known continued fraction. 
// USE: Example.
/*
int main() {
    int a0 = 1; // The integer part of the square root of your number
    std::vector<int> period_or_tail = {2, 2, 2, 2}; // Already known continued-fraction terms a1..ak
    double eps = 0.0001; // Desired error threshold

    auto res = Approximation(a0, period_or_tail, eps);
    int ok = res.first;            // 1 if approximation reached, 0 otherwise
    double approx = res.second.first; // best p_k / q_k value
    double bound = res.second.second; // Error bound
}
*/