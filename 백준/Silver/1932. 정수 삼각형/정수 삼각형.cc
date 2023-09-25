#include <iostream>

int N, num;
int dp[600][600];

int main() {
    std::cin >> N;
    std::cin >> dp[0][0];
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i+1; j++){
            std::cin >> num;
            if(j == 0){
                dp[i][0] = dp[i-1][0] + num;
            }
            else{
                if(dp[i-1][j-1] > dp[i-1][j]) dp[i][j] = dp[i-1][j-1] + num;
                else dp[i][j] = dp[i-1][j] + num;
            }
        }
    }

    int max = -1;
    for(int i = 0; i < N; i++){
        if(max < dp[N-1][i]) max = dp[N-1][i];
    }

    std::cout << max;
}