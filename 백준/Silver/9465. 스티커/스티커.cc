#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T, N;
int score[2][100001];
int dp[2][100001];

int main(){
    cin >> T;

    for(int i = 0; i < T; i++){
        fill_n(dp[0], 100001, 0);
        fill_n(dp[1], 100001, 0);
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> score[0][j];
        }
        for(int j = 0; j < N; j++){
            cin >> score[1][j];
        }

        dp[0][0] = score[0][0];
        dp[1][0] = score[1][0];

        dp[0][1] = dp[1][0] + score[0][1];
        dp[1][1] = dp[0][0] + score[1][1];

        for(int j = 2; j < N; j++){
            for(int k = 0; k < 2; k++){
                dp[k][j] = score[k][j] + max(dp[(k+1)%2][j-1], dp[(k+1)%2][j-2]);
            }
        }

        int result = 0;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < N; k++){
                result = max(result, dp[j][k]);
            }
        }
        cout << result << "\n";
    }
}