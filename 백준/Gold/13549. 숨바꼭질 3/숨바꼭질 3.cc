#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
queue<pair<int, int>> q;
int visited[100001];

int teleport(int x){
    return 2*x;
}

int movePlus(int x){
    return x+1;
}

int moveMinus(int x){
    return x-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    int start = N;
    int end = K;

    q.emplace(start, 0);

    fill_n(visited, 100001, -1);
    visited[start] = 0;

    int m1, m2, tp;
    while (!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();

        if(cur.first == end){
            cout << cur.second;
            break;
        }

        m1 = -1; m2 = -1; tp = -1;
        if(cur.first <= 50000) tp = teleport(cur.first);
        if(cur.first > 0) m1 = moveMinus(cur.first);
        if(cur.first < 100000) m2 = movePlus(cur.first);

        if(tp != -1 && (visited[tp] == -1 || visited[tp] > cur.second)) {q.emplace(tp, cur.second); visited[tp] = cur.second;}
        if(m1 != -1 && (visited[m1] == -1 || visited[m1] > cur.second+1)) {q.emplace(m1, cur.second+1); visited[m1] = cur.second+1;}
        if(m2 != -1 && (visited[m2] == -1 || visited[m2] > cur.second+1)) {q.emplace(m2, cur.second+1); visited[m2] = cur.second+1;}

    }
}