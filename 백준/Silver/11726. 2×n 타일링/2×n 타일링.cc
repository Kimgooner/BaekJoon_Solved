#include <iostream>
using namespace std;
int dp[1005];

int main(){
    dp[1] = 1;
    dp[2] = 2;

    int n;
    for(int i = 3; i <= 1000; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 10007;
    }

    cin >> n;
    cout << dp[n];
}
