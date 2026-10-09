#include "DiscMath.h"
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <map>
#include <algorithm>


spanningTreeEdgesReturnable KruskalsAlgorithm(std::vector<std::vector<int>> List) {
    int n = List.size(), counter = 0, totalWeight = 0;
    std::vector<Edge> edges;
    std::vector<Edge> spanningTreeEdges;
    struct spanningTreeEdgesReturnable answer;

    for (int i = 0; i < List.size(); ++i) {
        for (int vertexto : List[i]) { 
            if (i < vertexto) {
                edges.push_back({ i, vertexto, 1 });
            }
        }
    }

    std::sort(edges.begin(), edges.end());

    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    auto find = [&](auto& self, int v) -> int {
        if (v == parent[v]) return v;
        return parent[v] = self(self, parent[v]);
        };

    for (const auto& edge : edges) {
        if (counter == n - 1) break; 

        int root_u = find(find, edge.e);
        int root_v = find(find, edge.v);

        if (root_u != root_v) {
            spanningTreeEdges.push_back(edge);
            parent[root_u] = root_v;  
            counter++;
        }
     
    }

    for (auto& edge : spanningTreeEdges) {
        totalWeight = totalWeight + edge.weight;
    }

    answer.totalWeight = totalWeight;
    answer.spanningTreeEdgesAnswer = spanningTreeEdges;

    return answer;

}