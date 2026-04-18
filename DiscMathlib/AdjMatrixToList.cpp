#include "DiscMath.h"
#include "pch.h"
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <map>

std::vector<std::vector<int>> AdjMatrixToList(std::vector<std::vector<int>> matrix) {

	if (matrix.empty()) { return {}; }
	if (matrix.size() != matrix[0].size()) { return {}; }

	int n = matrix.size();
	int m = n;
	std::vector<std::vector<int>> AdjList(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 1) {
    AdjList[i].push_back(j);
}
		}
	}

	return AdjList;
}
