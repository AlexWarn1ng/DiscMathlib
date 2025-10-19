#include <string>
#include <vector>

int FractionalPart (int mk, int dk, int a0, int afirst, std::vector<int>& out) {
	int matrix[100][100];

	matrix[1][0] = dk * a0 - mk;
	matrix[1][1] = (afirst - (matrix[1][0] * matrix[1][0])) / dk;
	matrix[1][2] = (a0 + matrix[1][0]) / matrix[1][1];
	int i = 2;
	while (true) {
		matrix[i][0] = matrix[i - 1][1] * matrix[i - 1][2] - matrix[i - 1][0];
		matrix[i][1] = (afirst - (matrix[i][0] * matrix[i][0])) / matrix[i - 1][1];
		matrix[i][2] = (a0 + matrix[i][0]) / matrix[i][1];
		if (matrix[i][2] == (2 * a0)) {
			break;
		}
		i++;
	}

	out.clear();
	out.reserve(i);
	for (int j = 1; j <= i; ++j) {
		out.push_back(matrix[j][2]);
	}
}