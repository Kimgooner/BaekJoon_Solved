#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    int lhs[N][M];
    int rhs[N][M];
    int result[N][M];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> lhs[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> rhs[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            result[i][j] = lhs[i][j] + rhs[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}
