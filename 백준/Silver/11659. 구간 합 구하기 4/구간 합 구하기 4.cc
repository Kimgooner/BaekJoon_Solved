#include <iostream>

int N, M;
int dp[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    int input;
    for(int i = 1; i <= N; i++){
        std::cin >> input;
        dp[i] = dp[i-1] + input;
    }

    int i, j;
    for(int k = 0; k < M; k++){
        std::cin >> i >> j;
        std::cout << dp[j] - dp[i-1] << "\n";
    }
}