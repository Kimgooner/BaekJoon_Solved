#include <iostream>

int N, M;
int chart[1030][1030];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;

    int input;
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= N; j++){
            std::cin >> input;
            chart[i][j] = chart[i][j-1] + input;
        }
    }

    int x1, y1, x2, y2;
    for(int i = 0; i < M; i++){
        std::cin >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        for(int j = 0; j <= x2 - x1; j++){
            res += chart[x1-1+j][y2] - chart[x1-1+j][y1-1];
        }
        std::cout << res << "\n";
    }
}