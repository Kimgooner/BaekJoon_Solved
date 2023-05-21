#include <iostream>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;

    int ans;
    for(int i = 1; i <= sqrt(N); i++){
        ans = i;
    }

    std::cout << ans;
}