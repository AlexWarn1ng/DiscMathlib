#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <utility>

std::pair<int, std::pair<double, double>> Approximation(int integer, std::vector<int>& Fracture, double approximationneeded) {
    int matrix[100][100], j = 0;
    for (int i = 0; i < static_cast<int>(Fracture.size()) + 2; i++) {
        if (i == 0) {
            matrix[1][2] = integer;
        }
        else {
            if (i != static_cast<int>(Fracture.size()) + 1) {
             matrix[1][j + 3] = Fracture[j];
            }
            else {
             matrix[1][j + 3] = Fracture[0];
            }
            j++;
        }
    }
    matrix[2][0] = 0; matrix[2][1] = 1;
    matrix[3][0] = 1; matrix[3][1] = 0;
    j = 0;
    int last = 3 + (int)Fracture.size();
    for (int i = 2; i <= last; ++i) {
        int ak = matrix[1][i];
        matrix[2][i] = ak * matrix[2][i - 1] + matrix[2][i - 2];
        matrix[3][i] = ak * matrix[3][i - 1] + matrix[3][i - 2];
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
