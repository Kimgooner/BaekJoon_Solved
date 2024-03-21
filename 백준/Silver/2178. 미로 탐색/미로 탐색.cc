#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N,M;
int map[105][105];
int visited[105][105];
int idx[2]{-1,1};

void bfs(){
    queue<pair<int,int>> q;
    q.emplace(0,0);
    visited[0][0] = 1;

    while (!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i = 0; i < 2; i++){
            if(cur.first + idx[i] >= 0 && cur.second >= 0 && map[cur.first+idx[i]][cur.second] != 0){
                if(!visited[cur.first+idx[i]][cur.second]){
                    visited[cur.first+idx[i]][cur.second] = 1;
                    map[cur.first+idx[i]][cur.second] = map[cur.first][cur.second] + 1;
                    q.emplace(cur.first+idx[i],cur.second);
                }
            }
            if(cur.first >= 0 && cur.second + idx[i] >= 0 && map[cur.first][cur.second+idx[i]] != 0){
                if(!visited[cur.first][cur.second+idx[i]]){
                    visited[cur.first][cur.second+idx[i]] = 1;
                    map[cur.first][cur.second+idx[i]] = map[cur.first][cur.second] + 1;
                    q.emplace(cur.first,cur.second+idx[i]);
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    string input;

    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            map[i][j] = input[j] - '0';
        }
    }
    bfs();
    cout << map[N-1][M-1];
}