# Functions
Extended euclidean algorithm

## DISCMATH_API std::pair<int, int> ExtendedEuclideanAlgorithm(int a, int b); 
### Purpose: 
Finds gcd(a, b) and coefficients x, y satisfying ax + by = gcd(a, b)
### use:
`
int main(){
funct(x, y)
answerX = res.first
answerY = res.second
}
`

## DISCMATH_API std::pair<int, int> ExtendedEuclideanAlgorithm(int a, int b); 
### Purpose: 
Constructs the periodic part of the continued fraction for sqrt(N)
### use:
`
int main(){
int m0 = 0, d1 = 1; //For classic tasks, do not recomended to change it
int A;  //The integer part of the square root of your number
int B; //The number under the square root
std::vector<int> vec;
FractionalPart(m0, d1, A, B, vec); // returns in vec, you do not need to make a variable
}
`

## DISCMATH_API std::pair<int, std::pair<double, double>> Approximation(int celoje, std::vector<int>& drobnijoststok, double prib);
### Purpose: 
Finds the best rational approximation based on an already known continued fraction. 
### use:
`
int main() {
    int a0 = 1; // The integer part of the square root of your number
    std::vector<int> period_or_tail = {2, 2, 2, 2}; // Already known continued-fraction terms a1..ak
    double eps = 0.0001; // Desired error threshold
    auto res = Approximation(a0, period_or_tail, eps);
    int ok = res.first;            // 1 if approximation reached, 0 otherwise
    double approx = res.second.first; // best p_k / q_k value
    double bound = res.second.second; // Error bound
}
`