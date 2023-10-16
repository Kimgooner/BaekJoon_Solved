#include <iostream>

int N, input;
int wine[10001];
int dp[10001][3];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    for(int i = 1; i <= N; i++){
        std::cin >> wine[i];
    }

    for(int i = 1; i <= N; i++){
        dp[i][1] = wine[i];
        dp[i][2] = wine[i] + dp[i-1][1];

        if(i >= 2){
            int buf = 0;
            for(int j = 1; j <= i-2; j++){
                if(buf < dp[j][2]) buf = dp[j][2];
                if(buf < dp[j][1]) buf = dp[j][1];
            }
            dp[i][1] = wine[i] + buf;
        }
    }

    int max = 0;
    for(int i = 0; i <= N; i++){
        if(max < std::max(dp[i][1], dp[i][2])) max = std::max(dp[i][1], dp[i][2]);
    }

    std::cout << max;
}