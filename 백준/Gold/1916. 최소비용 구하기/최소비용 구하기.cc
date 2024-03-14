#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct node {
    int to;
    int dist;

    bool operator<(const node& other) const {
        return dist < other.dist;
    }

    bool operator>(const node& other) const {
        return dist > other.dist;
    }

    bool operator==(const node& other) const {
        return dist == other.dist;
    }

}node;

vector<node> v[2000];
int dist[2000];

void dijkstra(int start) {
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        int curcost = pq.top().dist;
        int cur = pq.top().to;
        pq.pop();

        if (dist[cur] < curcost){
            continue;
        }
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].to;
            int nextcost = curcost + v[cur][i].dist;

            if (dist[next] > nextcost){
                pq.push({next, nextcost});
                dist[next] = nextcost;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    int point1, point2;
    cin >> n >> e;
    for (int i = 1; i <= n; i++) {
        dist[i] = 2000000000;
    }
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});

    }
    cin >> point1 >> point2;
    dijkstra(point1);
    cout << dist[point2];
}