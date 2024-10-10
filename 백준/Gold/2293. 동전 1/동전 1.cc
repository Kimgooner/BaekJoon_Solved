#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 동전의 개수 저장
// 동전은 최대 100개

// 합산은 최대 10000까지 => 10000 < 동전 버림

int dp[10001];
int n, k, coin;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coins;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> coin;
        if(coin <= 10000) coins.push_back(coin);
    }

    sort(coins.begin(), coins.end());
    dp[0] = 1;

    for(int c : coins){
        for(int j = c; j <= k; j++) {
            dp[j] += dp[j - c];
        }
    }
    cout << dp[k];
}