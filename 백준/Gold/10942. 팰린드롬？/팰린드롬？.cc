#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int numbers[2001];
bool dp[2001][2001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> numbers[i];
    }

    for(int i = 1; i <= N; i++){
        dp[i][i] = true;
    }

    for(int i = 1; i < N; i++){
        dp[i][i+1] = numbers[i] == numbers[i+1];
    }

    for(int step = 2; step < N; step++){
        for(int i = 1; i <= N - step; i++){
            dp[i][i+step] = numbers[i] == numbers[i+step] && dp[i+1][i+step-1];
        }
    }

    cin >> M;
    int S,E;
    for(int i = 0; i < M; i++){
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }

}