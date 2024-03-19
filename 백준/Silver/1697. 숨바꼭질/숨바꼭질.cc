#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> points[100005];
int visited[100005];
int t[100005];

void bfs(int start, int end){
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int v : points[cur]){
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
                t[v] = t[cur] + 1;
            }

            if(v == end){
                cout << t[v];
                return;
            }
        }
    }
}

int main(){
    int N,K;
    cin >> N >> K;

    for(int i = 0; i <= 100000; i++){
        if(i == 0){
            points[i].push_back(i+1);
            points[i].push_back(i*2);
        }

        if(i <= 50000){
            points[i].push_back(i-1);
            points[i].push_back(i+1);
            points[i].push_back(i*2);
        }
        else{
            points[i].push_back(i-1);
            points[i].push_back(i+1);
        }
    }
    bfs(N,K);
}