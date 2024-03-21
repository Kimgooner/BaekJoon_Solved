#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int M,N,V;
vector<int> vertex[1005];
int visited[2][1005];

void dfs(int n){
    cout << n << " ";
    for(int v : vertex[n]){
        if(!visited[0][v]) {
            visited[0][v] = 1;
            dfs(v);
        }
    }
}

void bfs(int n){
    queue<int> q;
    q.push(n);
    visited[1][n] = 1;
    cout << n << " ";

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int v : vertex[cur]){
            if(!visited[1][v]) {
                cout << v << " ";
                visited[1][v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> N >> M >> V;

    int x, y;
    while(M--){
        cin >> x >> y;
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }

    for(int i = 0; i < 1000; i++){
        sort(vertex[i].begin(), vertex[i].end());
    }
    visited[0][V] = 1;
    dfs(V);
    cout << "\n";
    bfs(V);
}
