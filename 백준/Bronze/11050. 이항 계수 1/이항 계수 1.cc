#include <iostream>

int factorial(int n){
    int ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
    }
    return ans;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    int ans = factorial(N) / (factorial(N - K) * factorial(K));
    std::cout << ans;
}