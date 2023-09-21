#include <iostream>

int N, input;
int dp[1000005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int max = -1001;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        if(dp[i-1] < 0) dp[i] = input;
        else dp[i] = dp[i-1] + input;

        if(max < dp[i]) max = dp[i];
    }
    std::cout << max;
}