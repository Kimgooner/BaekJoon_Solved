#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[1005];
int visited[1005];

void bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int v : graph[cur]){
            if(visited[v] == 0){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int N, M;
int main(){
    cin >> N >> M;

    int v1, v2;
    for(int i = 0; i < M; i++){
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int count = 0;
    for(int i = 1; i <= N; i++) {
        if (visited[i] != 1) {
            bfs(i);
            count++;
        }
    }
    cout << count;
}

