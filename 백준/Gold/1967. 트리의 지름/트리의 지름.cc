#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

vector<pair<int,int>> tree[10001];
int N;
int visited[10001];

void dfs(int cur, int dist){
    for(int i = 0; i < tree[cur].size(); i++){
        if(visited[tree[cur][i].first] == -1){
            visited[tree[cur][i].first] = dist + tree[cur][i].second;
            dfs(tree[cur][i].first, dist + tree[cur][i].second);
        }
    }
}

int main(){
    cin >> N;

    int a,b,c;
    for(int i = 0; i < N-1; i++){
        cin >> a >> b >> c;
        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }

    fill_n(visited, 10001, -1);
    visited[1] = 0;
    dfs(1, 0);

    int max_dist = 0, max_node = 1;
    for(int i = 1; i <= N; i++){
        if(max_dist < visited[i]){
            max_node = i;
            max_dist = visited[i];
        }
    }

    fill_n(visited, 10001, -1);
    visited[max_node] = 0;
    dfs(max_node, 0);
    max_dist = 0;
    for(int i = 1; i <= N; i++){
        max_dist = max(max_dist, visited[i]);
    }

    cout << max_dist;
}