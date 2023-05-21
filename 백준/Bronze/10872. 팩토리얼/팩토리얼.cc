#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int ans = 1;
    for(int i = 1; i <= N; i++){
        ans *= i;
    }
    std::cout << ans;
}