#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int box[1005][1005];
int visited[1005][1005];
int count = 0, buf_count;
int pass = 0;
int N,M;
int b_size;
int idx[2]{-1,1};

void bfs(vector<pair<int,int>> &v){
    queue<vector<pair<int,int>>> q;
    q.push(v);
    for(pair<int,int> p : v){
        visited[p.first][p.second] =  1;
    }

    while(!q.empty()){
        vector<pair<int,int>> cur = q.front();
        q.pop();
        buf_count = count;

        vector<pair<int,int>> buf;
        for(pair<int,int> p : cur){
            for(int i = 0; i < 2; i++){
                if(p.first + idx[i] < M && p.first + idx[i] >= 0 && p.second >= 0){
                    if(!visited[p.first+idx[i]][p.second] && box[p.first+idx[i]][p.second] == 0){
                        box[p.first+idx[i]][p.second] = 1;
                        visited[p.first+idx[i]][p.second] = 1;
                        buf.emplace_back(p.first+idx[i], p.second);
                        count++;
                    }
                }
                if(p.first >= 0 && p.second + idx[i] >= 0 && p.second + idx[i] < N){
                    if(!visited[p.first][p.second+idx[i]] && box[p.first][p.second+idx[i]] == 0){
                        box[p.first][p.second+idx[i]] = 1;
                        visited[p.first][p.second+idx[i]] = 1;
                        buf.emplace_back(p.first, p.second+idx[i]);
                        count++;
                    }
                }
            }
        }
        pass++;
        if(count == buf_count){
            cout << -1;
            break;
        }
        else if(count == b_size){
            cout << pass;
            break;
        }
        else {
            q.push(buf);
        }
    }


}

int main(){
    cin >> N >> M;
    b_size = N * M;
    vector<pair<int,int>> entries;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                count++;
                entries.emplace_back(i,j);
            }
            else if(box[i][j] == -1){
                b_size--;
            }
        }
    }
    if(b_size == count) cout << 0;
    else bfs(entries);
}