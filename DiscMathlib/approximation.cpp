#include "DiscMath.h"
#include "pch.h"
#include <vector>
#include <cstdlib>
#include <utility>

std::pair<int, std::pair<double, double>> Approximation(int integer, std::vector<int>& Fracture, double approximationneeded) {
    if (Fracture.size() == 1 && Fracture[0] == 0) {
        return { 1, { (double)integer, 0.0 } };  // error 0 (In case of a perfect square)
    }

    int matrix[100][100] = {}; //Filling with 0 to insure no garbage values
    int j = 0;
    int col = 2;
    matrix[1][col++] = integer;

    int periodLen = static_cast<int>(Fracture.size());
    if (periodLen == 0) {
        return { 0, { (double)integer, std::numeric_limits<double>::infinity() } };
    }

    int maxPeriods = 5;
    int maxCols = 99; 
    for (int t = 0; t < periodLen * maxPeriods && col < maxCols; ++t) {
        int idx = t % periodLen;          
        matrix[1][col++] = Fracture[idx];
    }
    int last = col - 1;

    matrix[2][0] = 0; matrix[2][1] = 1;
    matrix[3][0] = 1; matrix[3][1] = 0;

    for (int i = 2; i <= last; ++i) {
        int ak = matrix[1][i];
        matrix[2][i] = ak * matrix[2][i - 1] + matrix[2][i - 2]; // p_k
        matrix[3][i] = ak * matrix[3][i - 1] + matrix[3][i - 2]; // q_k
    }

    bool found = false;
    double approx = 0.0;
    double bound = 0.0;
    int ok = 0;

    for (int i = 2; i <= last - 1; ++i) {
        int ak_next = matrix[1][i + 1];
        int pk = matrix[2][i];
        int qk = matrix[3][i];
        bound = 1.0 / ((double)ak_next * qk * qk);

        if (bound < approximationneeded) {
            approx = (double)pk / qk;
            found = true;
            ok = 1;
            break;
        }
    }
    if (!found) {
        int i = last - 1;
        int ak_next = matrix[1][i + 1];
        int pk = matrix[2][i];
        int qk = matrix[3][i];
        bound = 1.0 / ((double)ak_next * qk * qk);
        approx = (double)pk / qk;
    }
    return std::make_pair(ok, std::make_pair(approx, bound));
}
