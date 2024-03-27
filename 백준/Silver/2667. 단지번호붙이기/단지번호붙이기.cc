#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N;
int map[30][30];
int idx[2]{-1,1};
vector<int> result;

int bfs(int x, int y){
    queue<pair<int,int>> q;
    q.emplace(x,y);
    map[x][y] = 0;

    int cnt = 1;

    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();

        for(int v : idx){
            if(cur.first + v >= 0 && map[cur.first+v][cur.second] == 1){
                q.emplace(cur.first+v,cur.second);
                map[cur.first+v][cur.second] = 0;
                cnt++;
            }
            if(cur.second + v >= 0 && map[cur.first][cur.second+v] == 1){
                q.emplace(cur.first,cur.second+v);
                map[cur.first][cur.second+v] = 0;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0 ; j < N; j++){
            map[i][j] = input[j] - '0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                result.push_back(bfs(i,j));
            }
        }
    }

    sort(result.begin(),result.end());
    cout << result.size() << "\n";
    for(int v : result){
        cout << v << "\n";
    }
}