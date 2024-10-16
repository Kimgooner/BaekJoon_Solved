#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[31];
int n;

int main(){
    cin >> n;

    dp[0] = 1;
    dp[2] = 3;
    dp[3] = 0;

    for(int i = 4; i <= 30; i++) {
        dp[i] = dp[i-2] * 4 - dp[i-4];
    }

    cout << dp[n];
}