#include "DiscMath.h"
#include "pch.h"
#include <vector>
#include <string>
#include <set>
#include <algorithm>

std::vector<int> GeneratePruferCode(std::vector<std::vector<int>> AdjList) {
	std::vector<int> code;
	int listSize = AdjList.size();
	std::set<int> candidate;
	int deleteto, removefrom, counter = 0;

	while (true) {
		for (int i = 0; i < listSize; i++) {
			if (AdjList[i].size() == 1) {
				candidate.insert(i);
			}
		}
		deleteto = *candidate.begin();
		removefrom = AdjList[deleteto][0];

		AdjList[removefrom].erase(std::remove(AdjList[removefrom].begin(), AdjList[removefrom].end(),deleteto),AdjList[removefrom].end());
		AdjList[deleteto].clear();

		code.push_back(removefrom);

		candidate.clear();
		counter++;

		if (counter == listSize - 2) {
			return code;
		}

	}
}
