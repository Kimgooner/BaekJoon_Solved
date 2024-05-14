#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
vector<int> edge[105];
int visited[105];

int bfs(int s, int e){
    fill_n(visited, 105, 0);
    queue<int> q;
    q.push(s);

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for(int v : edge[cur]){
            if(!visited[v]){
                if(v == e) return 1;
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    int input;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> input;
            if(input == 1) edge[i].push_back(j);
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) {
            cout << bfs(i,j) << " ";
        }
        cout << "\n";
    }
}
