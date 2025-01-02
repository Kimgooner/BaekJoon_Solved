#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int grid[501][501];
vector<int> resultSet;

bool isValid(int x, int y){
    return x >= 0 && y >=0 && x < N && y < M;
}

int getShapeValue(int x, int y, int r){
    int sum = grid[x][y];
    for(int i = 0; i < 4; i++){
        if(i == r) continue;
        if(isValid(x+dx[i], y+dy[i])) sum += grid[x+dx[i]][y+dy[i]];
    }
    return sum;
}

void makeShape(int x, int y){ // ㅓ, ㅜ, ㅏ, ㅗ
    int resultMax = 0;
    if(x >= 1 && y >= 1 && x < N-1 && y < M){
        resultMax = max(resultMax, getShapeValue(x,y,2));
    }
    if(x >= 0 && y >= 1 && x < N-1 && y < M-1){
        resultMax = max(resultMax, getShapeValue(x,y,1));
    }
    if(x >= 1 && y >= 0 && x < N-1 && y < M-1){
        resultMax = max(resultMax, getShapeValue(x,y,3));
    }
    if(x >= 1 && y >= 1 && x < N && y < M-1){
        resultMax = max(resultMax, getShapeValue(x,y,0));
    }
    resultSet.push_back(resultMax);
}

int dfs_result = 0;
void dfs(int depth, int cur_x, int cur_y, int prev_x, int prev_y){
    if(depth == 3){
        if(isValid(cur_x, cur_y)){
            dfs_result += grid[cur_x][cur_y];
            resultSet.push_back(dfs_result);
            dfs_result -= grid[cur_x][cur_y];
        }
    }
    else{
        for(int i = 0; i < 4; i++){
            if(isValid(cur_x, cur_y) && (cur_x+dx[i] != prev_x || cur_y+dy[i] != prev_y)){
                dfs_result += grid[cur_x][cur_y];
                dfs(depth+1, cur_x+dx[i], cur_y+dy[i], cur_x, cur_y);
                dfs_result -= grid[cur_x][cur_y];
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            dfs(0, i, j, -1, -1);
            makeShape(i, j);
        }
    }

    sort(resultSet.begin(), resultSet.end());
    cout << *(resultSet.end()-1);
}