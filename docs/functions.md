# Functions

## DISCMATH_API std::pair<int, int> ExtendedEuclideanAlgorithm(int a, int b); 
### Purpose: 
Finds gcd(a, b) and coefficients x, y satisfying ax + by = gcd(a, b)
### use:
int main() {
    auto res = ExtendedEuclideanAlgorithm(10, 15);
    int answerX = res.first;
    int answerY = res.second;
}

## DISCMATH_API void FractionalPart(int m0, int d1, int A, int B, std::vector<int>& vec); 
### Purpose: 
Constructs the periodic part of the continued fraction for sqrt(N)
### use:
int main() {
    int m0 = 0, d1 = 1; // For classic tasks, do not recommended to change it
    int A = 3;  // The integer part of the square root of your number
    int B = 10; // The number under the square root
    std::vector<int> vec;
    FractionalPart(m0, d1, A, B, vec); // returns in vec, you do not need to make a variable
}

## DISCMATH_API std::pair<int, std::pair<double, double>> Approximation(int integer, std::vector<int>& fracture, double approximationneeded);
### Purpose: 
Finds the best rational approximation based on an already known continued fraction. 
### use:
int main() {
    int a0 = 1; // The integer part of the square root of your number
    std::vector<int> period_or_tail = {2, 2, 2, 2}; // Already known continued-fraction terms a1..ak
    double eps = 0.0001; // Desired error threshold
    auto res = Approximation(a0, period_or_tail, eps);
    int ok = res.first;            // 1 if approximation reached, 0 otherwise
    double approx = res.second.first; // best p_k / q_k value
    double bound = res.second.second; // Error bound
}

## DISCMATH_API std::vector<std::vector<int>> AdjMatFromSeqAlpha(std::vector<std::string> sequence, std::string type);
### Purpose: 
Makes adjacency matrix from a sequence of edges. For example, given an edge list A = {(A,B), (B,C), (C,D), (D,M)}, we need to construct an adjacency matrix. Since the graph can be either directed or undirected, the function handle both types.
Parameters:
std::vector<std::string> sequence | Our sequence
std::string type | type of graph needed, DIR - directed, NDIR - undirected
### use:
int main() {
    std::vector<std::string> someStuff = {"AB", "BC", "CD"};
    std::vector<std::vector<int>> ans = AdjMatFromSeqAlpha(someStuff, "DIR");
    // std::vector<std::vector<int>> ans = AdjMatFromSeqAlpha(someStuff, "NDIR"); // or undirected
}

## DISCMATH_API std::vector<std::vector<int>> AdjMatrixToList(std::vector<std::vector<int>> matrix);
### Purpose: 
In some cases we need to convert matrix to a list for calculations.
Parameters:
std::vector<std::vector<int>> matrix | Adjacency matrix 
### use:
int main() {
    std::vector<std::vector<int>> matrix = {{0, 1}, {1, 0}};
    std::vector<std::vector<int>> ans = AdjMatrixToList(matrix);
}

## DISCMATH_API std::vector<int> GeneratePruferCode(std::vector<std::vector<int>> AdjList);
### Purpose: 
Prufer code helps to store huge trees efficiently and decode them. This implementation handles trees without cycles.
READ MORE: https://wikipedia.org
Parameters:
std::vector<std::vector<int>> AdjList | Adjacency list
### use:
int main() {
    std::vector<std::vector<int>> AdjList = {{1}, {0, 2}, {1}};
    std::vector<int> ans = GeneratePruferCode(AdjList);
}








