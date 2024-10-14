#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int dp[30001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    int input;
    vector<int> coin;
    for(int i = 1; i <= n; i++){
        cin >> input;
        if(input <= 10000) coin.push_back(input);
    }

    dp[0] = 1;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(dp[i+coin[j]] > dp[i] + 1 && dp[i] != 0) dp[i+coin[j]] = dp[i] + 1;
            if(dp[i+coin[j]] == 0 && dp[i] != 0) dp[i+coin[j]] = dp[i] + 1;
        }
    }
    if(dp[k] == 0) cout << -1;
    else cout << dp[k] - 1;
//    cout << coin[1] << coin[2] << coin[3] << "\n";
//    for(int i = 0; i <= k; i++) cout << dp[i] << "\n";
}