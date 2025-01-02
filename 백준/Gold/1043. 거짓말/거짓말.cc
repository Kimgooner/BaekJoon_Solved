#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int P;

bool people[51];
bool party[51];
bool visited[51];
vector<int> people_connection[51];
vector<int> participants[51];

void bfs(int n){
    queue<int> q;
    fill_n(visited, 51, false);
    q.push(n);
    visited[n] = true;

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for(int v : people_connection[cur]){
            if(!visited[v]){
                q.push(v);
                people[v] = true;
                visited[v] = true;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    cin >> P;

    int num;
    for(int i = 0; i < P; i++){
        cin >> num;
        people[num] = true;
    }

    for(int i = 1; i <= M; i++){
        cin >> P;
        for(int j = 0; j < P; j++){
            cin >> num;
            participants[i].push_back(num);
        }

        for(int p : participants[i]){
            for(int v: participants[i]){
                if(p != v) people_connection[p].push_back(v);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        if(people[i]){
            bfs(i);
        }
    }

    int result = 0;
    for(int i = 1; i <= M; i++){
        for(int v : participants[i]){
            if(people[v]){
                result++;
                break;
            }
        }
    }

    cout << M - result;
}