#include <iostream>

int N;
int inputs[1001];
int dp[1001];

int main() {
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> inputs[i];
    }

    for(int i = 0; i < N; i++) {
        int max = 0;
        for(int j = 0; j < inputs[i]; j++){
            if(max < dp[j]) max = dp[j];
        }
        dp[inputs[i]] = max + 1;
    }

    int max = 0;
    for(int i = 0; i < 1001; i++){
        if(max < dp[i]) max = dp[i];
    }

    std::cout << max;
}