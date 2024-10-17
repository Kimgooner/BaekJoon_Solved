#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define mod 1000000

int dp[5001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    size_t size = input.size();

    dp[0] = 1;
    if(input[0] != '0') dp[1] = 1;

    for(int i = 2; i <= size; i++){
        if(input[i-1] != '0') dp[i] = (dp[i] + dp[i-1]) % mod;
        if(input[i-2] != '0' && (input[i-2]-'0')*10 + (input[i-1]-'0') <= 26) dp[i] = (dp[i] + dp[i-2]) % mod;
    }

    cout << dp[size];
/*
    cout << "\n";
    for(int i = 1; i <= size; i++){
        cout << dp[i] << "\n";
    }
*/
}