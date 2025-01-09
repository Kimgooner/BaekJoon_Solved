#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

int V, E, S;
vector<pair<int,int>> graph[20001];
int d[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while (!pq.empty()){
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d[cur] < dist) continue;

        for(int i = 0; i < graph[cur].size(); i++){
            int cost = dist + graph[cur][i].second;

            if(cost < d[graph[cur][i].first]){
                d[graph[cur][i].first] = cost;
                pq.push(make_pair(-cost, graph[cur][i].first));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> V >> E >> S;

    int u, v, w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    fill_n(d, 20001, INF);
    dijkstra(S);

    for(int i = 1; i <= V; i++){
        if(d[i] == INF) { cout << "INF\n"; continue; }
        cout << d[i] << "\n";
    }
}
