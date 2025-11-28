#pragma once
#include <vector>
#include "DiscMath.h"
#include "pch.h"
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

/*
 Version 1.1 changes
 FractionalPart function:
Added a check to avoid counting perfect roots and dividing by 0 in the function logic*. (This was causing crashes.)
Added a check for repetitions in the function, meaning that a period that includes only one number is written to the vector as a single number. 
(Previously, due to the lack of a check, the following occurred: B = 10 | vec = 6 6 Now the function returns B = 10 | vec = 6.)
This is the number under the square root, and vec is the return vector of the periodic continued fraction.)

Approximation function:
Added a check for perfect squares. This avoids errors similar to FractionalPart.
The approximation logic has been completely redesigned. Now the approximation cycle runs through several periods simultaneously. That is, 
if the period "1 2 3 4 5" is passed to the function, the function will construct an approximation based on the period "1 2 3 4 5 1 2 3 4 5 1 2 3 4 5"**.
This fixes the problem of an unfound approximation, where an approximation exists but the function can't find it.

* - don't try to construct a continued fraction for an integer (there's no nontrivial periodic part)
** - the period is repeated as many times as it can fit within the matrix length constraint matrix[100][100]
That is, there can't be more than 100 numbers. BUT! We don't require the period to fit completely, which means if there's not enough space to insert it completely, 
we insert only the numbers that fit, and don't insert any remaining numbers after the boundary is crossed.
*/



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
