#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int result[100001];
int visited[100001];
vector<int> connection[100001];

void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for(int v : connection[cur]){
            if(!visited[v]){
                result[v] = cur;
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}

int main(){
    cin >> N;

    int s, e;
    for(int i = 0; i < N-1; i++){
        cin >> s >> e;
        connection[s].push_back(e);
        connection[e].push_back(s);
    }

    bfs();

    for(int i = 2; i <= N; i++){
        cout << result[i] << "\n";
    }
}