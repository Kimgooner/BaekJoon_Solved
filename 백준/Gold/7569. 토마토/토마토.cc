#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int box[105][105][105];
int M, N, H;
int visited[105][105][105];
int needs = 0, cnt = -1;

int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

void print(int h){
    for(int i = 0; i < N;i++){
        for(int j = 0; j < M; j++){
            cout << box[h][i][j] << " ";
        }
        cout << "\n";
    }
}

bool isValid(int z, int x, int y){
    return z >= 0 && z < H && x >= 0
    && x < N && y >= 0 && y < M
    && !visited[z][x][y] && box[z][x][y] == 0;
}

void bfs(vector<vector<int>> s){
    queue<vector<vector<int>>> q;
    q.push(s);

    while (!q.empty()){
        vector<vector<int>> cur = q.front();
        q.pop();

        vector<vector<int>> buf;
        for(vector<int> v : cur){
            int z = v[0];
            int x = v[1];
            int y = v[2];
            for(int i = 0; i < 6; i++){
                int nz = z + dz[i];
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isValid(nz,nx,ny)) {
                    box[nz][nx][ny] = 1;
                    vector<int> buff = {nz, nx, ny};
                    buf.push_back(buff);
                    needs--;
                }
            }
        }
        cnt++;
        if(!buf.empty()) q.push(buf);
        else return;
    }
}

int main(){
    cin >> M >> N >> H;
    vector<vector<int>> start;
    needs = H*N*M;
    for(int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> box[k][i][j];
                if(box[k][i][j] == 1) {
                    vector<int> buf = {k,i,j};
                    start.push_back(buf);
                    needs--;
                }
                else if(box[k][i][j] == -1) needs--;
            }
        }
    }
    if(needs == 0) cout << 0;
    else{
        bfs(start);
        if(needs == 0) cout << cnt;
        else cout << -1;
    }
}