#include <iostream>
#include <vector>
#include <algorithm>

int N;
double K, input;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;
    std::vector<double> coins;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        coins.push_back(input);
    }

    int cnt = 0, mul;
    for(int i = N-1; i >= 0; i--){
        mul = K / coins[i];
        K = K - (coins[i]*mul);
        cnt = cnt + mul;
        if(K == 0) break;
    }
    std::cout << cnt;
}