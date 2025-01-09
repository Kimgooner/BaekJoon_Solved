#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

int N, M;
int d[101][101];

void floydWarshall(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    for(int i = 1; i <= 100; i++){
        fill_n(d[i], 101, INF);
    }

    for(int i = 1; i <= N; i++){
        d[i][i] = 0;
    }

    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        if(d[a][b] != INF && c > d[a][b]) continue;
        d[a][b] = c;
    }

    floydWarshall();

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(d[i][j] == INF) { cout << 0 << " "; continue; }
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}