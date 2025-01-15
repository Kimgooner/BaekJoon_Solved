#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

int TC, N, M, W;
int S, E, T;
int dist[501];
bool visited[501];

bool BellmanFord(vector<pair<int,int>> vec[], int start){
    fill_n(dist, 501, INF);
    dist[start] = 0;
    bool isCycle = false;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(dist[j] == INF) continue;
            for(int k = 0; k < vec[j].size(); k++){
                int next = vec[j][k].first;
                int cost = vec[j][k].second;

                if(dist[j] != INF && dist[next] > dist[j] + cost){
                    dist[next] = dist[j] + cost;
                    if(i == N) isCycle = true;
                }
            }
        }
    }
    return isCycle;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> N >> M >> W;
        fill_n(visited, 501, false);
        vector<pair<int,int>> route[501];
        for(int j = 0; j < M; j++){
            cin >> S >> E >> T;
            route[S].emplace_back(E, T);
            route[E].emplace_back(S, T);
        }
        for(int j = 0; j < W; j++){
            cin >> S >> E >> T;
            route[S].emplace_back(E, -T);
        }

        bool hasNegativeCycle = false;

        for(int j = 1; j <= N; j++){
            if(!visited[j]){
                if(BellmanFord(route, j)){
                    hasNegativeCycle = true;
                    break;
                }

                for(int k = 1; k <= N; k++){
                    if(dist[k] != INF) visited[k] = true;
                }
            }
        }

        if(hasNegativeCycle) cout << "YES\n";
        else cout << "NO\n";
    }
}
