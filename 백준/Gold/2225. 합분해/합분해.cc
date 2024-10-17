#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define sum 201
#define cnt 201
#define mod 1000000000

using namespace std;

int dp[sum][cnt];
int N, K;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;

    for(int i = 0; i <= N; i++){
        dp[i][1] = 1;
    }

    for(int i = 1; i <= K; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= N; k++){
                if(j+k <= N && i+1 <= K) dp[j+k][i+1] = (dp[j+k][i+1] + dp[j][i]) % mod;
            }
        }
    }
/*
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= N; j++) {
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }
*/
    cout << dp[N][K];
}