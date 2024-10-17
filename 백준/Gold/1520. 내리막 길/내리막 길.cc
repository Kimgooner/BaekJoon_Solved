#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int grid[501][501];
int dp[501][501];

int N, M, result = 0;

bool isCorrect(int x, int y, int cur){
    return x >= 1 && x <= N && y >= 1 && y <= M && grid[x][y] > cur;
}

int dfs(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];

    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isCorrect(nx, ny, grid[x][y])) {
            cnt += dfs(nx,ny);
        }
    }

    dp[x][y] = cnt;
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i <= 500; i++){
        for(int j = 1; j <= 500; j++){
            dp[i][j] = -1;
        }
    }

    dp[1][1] = 1;
    dfs(N,M);
/*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
*/
    cout << dp[N][M];
}
