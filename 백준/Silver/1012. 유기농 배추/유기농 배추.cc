#include <iostream>
#include <queue>

int T;
int farm[55][55];

void bfs(int x, int y, int m, int n){
    std::queue<std::pair<int,int>> q;
    q.emplace(x,y);
    std::pair<int,int> cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        farm[cur.first][cur.second] = 0;
        if(cur.first - 1 >= 0 && farm[cur.first-1][cur.second]){
            q.emplace(cur.first-1, cur.second);
            farm[cur.first-1][cur.second] = 0;
        }
        if(cur.second - 1 >= 0 && farm[cur.first][cur.second-1]){
            q.emplace(cur.first, cur.second-1);
            farm[cur.first][cur.second-1] = 0;
        }
        if(cur.first + 1 < m && farm[cur.first+1][cur.second]){
            q.emplace(cur.first+1, cur.second);
            farm[cur.first+1][cur.second] = 0;
        }
        if(cur.second + 1 < n && farm[cur.first][cur.second+1]){
            q.emplace(cur.first, cur.second+1);
            farm[cur.first][cur.second+1] = 0;
        }
    }


}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;
    int M, N, K;
    for(int i = 0; i < T; i++){
        std::cin >> M >> N >> K;
        int X, Y;
        for(int j = 0; j < K; j++) {
            std::cin >> X >> Y;
            farm[X][Y] = 1;
        }
        int cnt = 0;
        for(int k = 0; k < M; k++){
            for(int l = 0; l < N; l++){
                if(farm[k][l] == 1) { bfs(k,l,M,N); cnt++;}
            }
        }
        std::cout << cnt << "\n";
    }
}