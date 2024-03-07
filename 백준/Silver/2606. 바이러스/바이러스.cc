#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;

vector<int> com[150];
vector<int> visited;

int virus_cnt = 0;

void bfs(){
    queue<int> q;
    q.push(1);
    visited.push_back(1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int a : com[cur]){
            bool isVisit = false;
            for(int b : visited){
                if(a == b) isVisit = true;
            }
            if(!isVisit) {visited.push_back(a); q.push(a); virus_cnt++;}
        }
    }
}

int main(){
    cin >> N >> M;
    int f,s;
    for(int i = 0; i < M; i++){
        cin >> f >> s;
        com[f].push_back(s);
        com[s].push_back(f);
    }

    bfs();
    cout << virus_cnt;
}
