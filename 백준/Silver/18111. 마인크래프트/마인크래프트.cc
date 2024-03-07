#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;
int N,M,B;
vector<int> chunk;

int main() {
    cin >> N >> M >> B;
    int map[500][500];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int cur_time = 1000000000, height;
    for(int i = 0; i <= 256; i++){
        int block = B;
        int time = 0;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if(map[j][k] >= i) {time += (2 * (map[j][k] - i)); block += (map[j][k] - i);}
                else {time += i - map[j][k]; block -= (i - map[j][k]);}
            }
        }

        if(block >= 0 && time <= cur_time) {cur_time = time; height = i;}
    }
    cout << cur_time << " " << height;
}