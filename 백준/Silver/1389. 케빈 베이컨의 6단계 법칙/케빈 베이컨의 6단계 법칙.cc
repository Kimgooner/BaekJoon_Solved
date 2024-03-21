#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N,M;
vector<int> ppl[105];

int bfs(int start){
    int sum = 0;
    int count = 1;
    int visited[105]{};
    queue<vector<int>> q;
    vector<int> first;
    first.push_back(start);
    q.push(first);
    visited[start] = 1;
    while(!q.empty()) {
        vector<int> buf;
        vector<int> cur = q.front();
        q.pop();
        for(int p : cur){
            for (int v: ppl[p]) {
                if (!visited[v]) {
                    sum += count;
                    visited[v] = 1;
                    buf.push_back(v);
                }
            }
        }
        if(buf.size() != 0) {
            q.push(buf);
            count++;
        }
    }
    return sum;
}

int main(){
    cin >> N >> M;
    int x, y;

    while (M--){
        cin >> x >> y;
        ppl[x].push_back(y);
        ppl[y].push_back(x);
    }

    int min = 2000000000;
    int min_idx;
    for(int i = 1; i <= N; i++){
        int cur = bfs(i);
        if(cur < min){
            min = cur;
            min_idx = i;
        }
    }
    cout << min_idx;
}