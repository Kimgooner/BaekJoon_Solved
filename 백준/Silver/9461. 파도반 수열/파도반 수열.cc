#include <iostream>

size_t P[105];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;

    for(int i = 5; i <= 100; i++){
        P[i] = P[i-2] + P[i-3];
    }

    int N, input;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        std::cout << P[input] << "\n";
    }
}