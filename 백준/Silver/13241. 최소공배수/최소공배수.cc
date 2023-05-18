#include <iostream>

int Euclidean(long long int a, long long int b){
    long long int r = a % b;
    if(r == 0) {
        return b;
    }
    return Euclidean(b, r);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long int A, B;
    std::cin >> A >> B;
    long long int max_div = Euclidean(A,B);
    std::cout << (A*B) / max_div;
}