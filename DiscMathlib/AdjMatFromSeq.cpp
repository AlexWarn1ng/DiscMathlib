#include "DiscMath.h"
#include "pch.h"
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <map>

std::vector<std::vector<int>> AdjMatFromSeqAlpha(std::vector<std::string> sequence, std::string type) {
    bool directed;
    if (type == "DIR") {
         directed = true;
    }
    else if (type == "NDIR") {
         directed = false;
    }
    else {
        return {}; //err
    }

    for (std::string term : sequence) {
        if (term.size() != 2) {
            return {}; //err
        }
        for (char letter : term) {
            if (!std::isalpha(static_cast<unsigned char>(letter))) {
                return {}; //err
            }
        }
    }

    std::set<char> vertexes;
    std::map<char, int> indexes;
    int counter = 0;

    for (const std::string& term : sequence) { // making set of all vertexes
        vertexes.insert(term[0]);
        vertexes.insert(term[1]);
    }

    for (char vertex : vertexes) { // giving vertexes a number
        indexes[vertex] = counter;
        counter++;
    }

    std::vector<std::vector<int>> AdjMatrix(vertexes.size(), std::vector<int>(vertexes.size(), 0));

    if (directed == true) {
        for (std::string term : sequence) {
            AdjMatrix[indexes[term[0]]][indexes[term[1]]] = 1; // direct
        }
    }
    else {
        for (std::string term : sequence) {
            AdjMatrix[indexes[term[0]]][indexes[term[1]]] = 1; // nondirect
            AdjMatrix[indexes[term[1]]][indexes[term[0]]] = 1;
        }
    }


    return AdjMatrix;

}