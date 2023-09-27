#include <iostream>

int N;
int dp[305][3];
int s[305];

int main() {
    std::cin >> N;
    for(int i = 1; i <= N; i++){
        std::cin >> s[i];
    }
    dp[0][0] = s[0];
    dp[1][1] = s[1] + dp[0][0];

    for(int i = 2; i <= N; i++){
        dp[i][1] = s[i] + std::max(dp[i-2][1], dp[i-2][2]);
        if(dp[i][1] < s[i] + dp[i-1][0]) dp[i][1] = s[i] + dp[i-1][0];
        dp[i][2] = s[i] + dp[i-1][1];
    }

    std::cout << std::max(dp[N][1], dp[N][2]);
}