#include "DiscMath.h"
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <map>
#include <algorithm>


//start of KruskalsAlgorithm.cpp
struct Edge {
    int e, v, weight;

    bool operator<(const Edge& other) const {
        if (weight < other.weight) {
            return true;
        }
        else {
            return false;
        }
    }
};

struct spanningTreeEdgesReturnable {
    int totalWeight;
    std::vector<Edge> spanningTreeEdgesAnswer;
};
//end of KruskalsAlgorithm.cpp