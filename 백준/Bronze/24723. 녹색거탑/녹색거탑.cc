#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int ans = 1;
    for(int i = 0; i < N; i++){
        ans *= 2;
    }
    std::cout << ans;
}