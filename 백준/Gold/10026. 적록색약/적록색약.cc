#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int grid[105][105];
int save[105][105];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int visited[105][105];
int v_save[105][105];

bool isValid(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y];
}

bool checkArea(bool weak, int x, int y, int c){
    if(weak){
        if(c == 1 || c == 2) return grid[x][y] == 1 || grid[x][y] == 2;
        return grid[x][y] == c;
    }
    return grid[x][y] == c;
}

void bfs(int s, int e, int c, bool weak){
    queue<pair<int,int>> q;
    q.emplace(s,e);

    while (!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(isValid(nx,ny) && checkArea(weak,nx,ny,c)){
                visited[nx][ny] = 1;
                grid[nx][ny] = 0;
                q.emplace(nx,ny);
            }
        }
    }
}

int main(){
    cin >> N;
    char input;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            switch (input) {
                case 'R':
                    grid[i][j] = 1;
                    break;
                case 'G':
                    grid[i][j] = 2;
                    break;
                case 'B':
                    grid[i][j] = 3;
                    break;
            }
        }
    }
    int cnt = 0;
    copy(&grid[0][0], &grid[0][0] + 11025, &save[0][0]);
    copy(&visited[0][0], &visited[0][0] + 11025, &v_save[0][0]);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j]) {bfs(i,j, grid[i][j], false); cnt++;}
        }
    }
    cout << cnt << " ";
    cnt = 0;
    copy(&save[0][0], &save[0][0] + 11025, &grid[0][0]);
    copy(&v_save[0][0], &v_save[0][0] + 11025, &visited[0][0]);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j]) {bfs(i,j, grid[i][j], true); cnt++;}
        }
    }
    cout << cnt;
}