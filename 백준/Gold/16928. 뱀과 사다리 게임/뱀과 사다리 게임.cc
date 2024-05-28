#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int snake[105];
int ladder[105];
int visited[105];
int cnt = 0;

void bfs(int s){
    queue<vector<int>> q;
    vector<int> start;
    start.push_back(s);
    q.push(start);

    while (!q.empty()){
        vector<int> cur = q.front();
        q.pop();

        vector<int> buf;
        for(int v : cur){
            if(v == 100) {cout << cnt; return;}
            if(!visited[v] && v < 100){
                visited[v] = 1;
                for(int i = 1; i <= 6; i++){
                    if(snake[v+i]){
                        buf.push_back(snake[v+i]);
                        continue;
                    }
                    if(ladder[v+i]){
                        buf.push_back(ladder[v+i]);
                        continue;
                    }
                    buf.push_back(v+i);
                }
            }
        }
        q.push(buf);
        cnt++;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int s, e;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        ladder[s] = e;
    }
    for(int i = 0; i < M; i++){
        cin >> s >> e;
        snake[s] = e;
    }
    bfs(1);
}