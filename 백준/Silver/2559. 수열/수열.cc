#include <iostream>

int N, K;
int dp[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> K;

    int input;
    for (int i = 1; i <= N; i++) {
        std::cin >> input;
        dp[i] = dp[i - 1] + input;
    }

    int max = -100 * 100000;
    for (int i = K; i <= N; i++) {
        int val = dp[i] - dp[i - K];
        if (max < val) max = val;
    }
    std::cout << max;
}
