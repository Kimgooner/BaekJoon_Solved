#include <iostream>

int main() {
    double X, N, a, b;
    std::cin >> X >> N;

    double sum = 0;

    for(int i = 0; i < N; i++){
        std::cin >> a >> b;
        sum += a*b;
    }
    if(X == sum) std::cout << "Yes";
    else std::cout << "No";
}