#include <iostream>

int main() {
    int N;

    std::cin >> N;
    long long ans = 1;
    for(int i = 0; i < N; i++){
        ans *= i+1;
    }
    std::cout << ans;
}