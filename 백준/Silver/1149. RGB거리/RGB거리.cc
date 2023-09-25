#include <iostream>

int N;
int n1, n2, n3;
int dp[1005][3];

int main() {
    std::cin >> N;
    std::cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for(int i = 1; i < N; i++){
        std::cin >> n1 >> n2 >> n3;

        if(dp[i-1][1] > dp[i-1][2]) dp[i][0] = n1 + dp[i-1][2];
        else dp[i][0] = n1 + dp[i-1][1];

        if(dp[i-1][0] > dp[i-1][2]) dp[i][1] = n2 + dp[i-1][2];
        else dp[i][1] = n2 + dp[i-1][0];

        if(dp[i-1][0] > dp[i-1][1]) dp[i][2] = n3 + dp[i-1][1];
        else dp[i][2] = n3 + dp[i-1][0];
    }
    int min = 2000000;
    for(int i = 0; i < 3; i++){
        if(min > dp[N-1][i]) min = dp[N-1][i];
    }

    std::cout << min;
}