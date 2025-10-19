#include "DiscMath.h"
#include "pch.h"
#include <utility>

std::pair<int, int> ExtendedEuclideanAlgorithm(int a, int b) {
	int i = 0, dliarashline = 1;
	int matrixotvetov[1000][5] = {};

	int result = b / a;
	int ostatok = b % a;
	matrixotvetov[1][i] = b; i++;
	matrixotvetov[1][i] = result; i++;
	matrixotvetov[1][i] = a; i++;
	matrixotvetov[1][i] = ostatok;
	i = 2; int j = 0;
	while (matrixotvetov[i - 1][3] != 0) {
		matrixotvetov[i][0] = matrixotvetov[i - 1][2];
		matrixotvetov[i][1] = matrixotvetov[i][0] / matrixotvetov[i - 1][3];
		matrixotvetov[i][2] = matrixotvetov[i - 1][3];
		matrixotvetov[i][3] = matrixotvetov[i][0] % matrixotvetov[i - 1][3];
		i++;

	}
	int start_back = i;
	int last = i - 1;
	//going back
	matrixotvetov[i][0] = 0; matrixotvetov[i][1] = 0; matrixotvetov[i][2] = b; matrixotvetov[i][3] = 1; matrixotvetov[i][4] = 0; ++i;
	matrixotvetov[i][0] = 1; matrixotvetov[i][1] = 0; matrixotvetov[i][2] = a; matrixotvetov[i][3] = 0; matrixotvetov[i][4] = 1; ++i;

	int linecount = 2;
	while (dliarashline <= last) {
		int q = matrixotvetov[dliarashline][1];
		int r = matrixotvetov[dliarashline][3];

		matrixotvetov[i][0] = dliarashline;
		matrixotvetov[i][1] = q;
		matrixotvetov[i][2] = r;
		matrixotvetov[i][3] = matrixotvetov[i - 2][3] - q * matrixotvetov[i - 1][3];
		matrixotvetov[i][4] = matrixotvetov[i - 2][4] - q * matrixotvetov[i - 1][4];

		i++; dliarashline++;

	}

	int temp1, temp2;
	temp1 = matrixotvetov[i - 2][3];
	temp2 = matrixotvetov[i - 2][4];
	return { temp1, temp2 };
}