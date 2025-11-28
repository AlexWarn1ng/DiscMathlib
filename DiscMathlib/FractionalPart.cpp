#include "DiscMath.h"
#include "pch.h"
#include <vector>

int FractionalPart (int mk, int dk, int a0, int afirst, std::vector<int>& out) {
	if (a0 * a0 == afirst) {
		out.clear();
		out.push_back(0);   //New check to not count ideal roots and avoid division by 0
		return 0;          
	}

	int matrix[100][100];

	matrix[1][0] = dk * a0 - mk;
	matrix[1][1] = (afirst - (matrix[1][0] * matrix[1][0])) / dk;
	matrix[1][2] = (a0 + matrix[1][0]) / matrix[1][1];
	int i = 1;
	while (true) {
		if (matrix[i][2] == 2 * a0) {
			break;                 		// Check row to avoid repetitions in result vector (Добавлено Новая проверка)
		}
		++i;
		matrix[i][0] = matrix[i - 1][1] * matrix[i - 1][2] - matrix[i - 1][0];
		matrix[i][1] = (afirst - (matrix[i][0] * matrix[i][0])) / matrix[i - 1][1];
		matrix[i][2] = (a0 + matrix[i][0]) / matrix[i][1];
	}

	out.clear();
	out.reserve(i);
	for (int j = 1; j <= i; ++j) {
		out.push_back(matrix[j][2]);
	}
	return i;
}