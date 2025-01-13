#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

int N, M, X;
vector<pair<int,int>> route[1001];
int d[1001][1001];

int dijkstra(int start, int end){
    priority_queue<pair<int,int>> pq;
    pq.emplace(0,start);
    d[start][start] = 0;

    while (!pq.empty()){
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d[start][cur] < dist) continue;
        for(int i = 0; i < route[cur].size(); i++){
            int cost = dist + route[cur][i].second;
            if(cost < d[start][route[cur][i].first]){
                d[start][route[cur][i].first] = cost;
                pq.emplace(-cost, route[cur][i].first);
            }
        }
    }
    return d[start][end];
}

int main(){
    cin >> N >> M >> X;

    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        route[a].emplace_back(b, c);
    }

    for(int i = 1; i <= 1000; i++){
        fill_n(d[i], 1001, INF);
    }
    int result = 0;
    for(int i = 1; i <= N; i++){
        result = max(result, dijkstra(i, X) + dijkstra(X, i));
    }
    cout << result;
}

// 가는데 걸리는 소요 시간(X -> all) -> 다익스트라
// 오는데 걸리는 소요 시간(all -> X) -> 흠...

// 우선순위 큐 다익스트라 시간 복잡고 -> O(NlogN)
// 총 시간 복잡도 = O(NlogN) + O(N^2logN)