#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1005][1005];
int visited[1005][1005];
int idx[2] = {-1,1};

void bfs(pair<int,int> p){
    queue<pair<int,int>> q;
    q.push(p);
    visited[p.first][p.second] = 1;
    map[p.first][p.second] = 0;

    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();

        for(int i = 0; i < 2; i++){
            if(cur.first+idx[i] >= 0 && cur.second >= 0) {
                if (!visited[cur.first + idx[i]][cur.second] && map[cur.first + idx[i]][cur.second]){
                    q.emplace(cur.first+idx[i],cur.second);
                    visited[cur.first + idx[i]][cur.second] = 1;
                    map[cur.first + idx[i]][cur.second] = map[cur.first][cur.second] + 1;
                }
            }

            if(cur.first >= 0 && cur.second+idx[i] >= 0) {
                if (!visited[cur.first][cur.second+idx[i]] && map[cur.first][cur.second+idx[i]]){
                    q.emplace(cur.first,cur.second+idx[i]);
                    visited[cur.first][cur.second+idx[i]] = 1;
                    map[cur.first][cur.second+idx[i]] = map[cur.first][cur.second] + 1;
                }
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    int x, y;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                x = i, y = j;
            }
        }
    }
    bfs({x,y});
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && map[i][j]){
                map[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}