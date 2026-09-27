#include "DiscMath.h"
#include "pch.h"
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <map>

int IsEulereanGraph(std::vector<std::vector<int>> List) {
	int numberOfNeededEdges = 0, iterations = 0, temp, size = List.size();

	while (iterations < size) 
	{
		temp = List[iterations].size();
		if ((temp % 2) != 0) {
			numberOfNeededEdges++;
		}
		if (numberOfNeededEdges > 2) {
			return 0;
		}
		iterations++;

	}
	if (numberOfNeededEdges == 2) {
		return 1;
	}
	else {
		return 2;
	}
}