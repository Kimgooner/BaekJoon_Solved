#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int child[205];
int dp[205];

int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> child[i];
    }

    for(int i = 1; i <= N; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(child[j] < child[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int result = 0;
    for(int i = 1; i <= N; i++){
        //cout << dp[i] << " ";
        result = max(result, dp[i]);
    }
    //cout << "\n";
    cout << N - result;
}