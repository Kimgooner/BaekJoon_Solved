#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    char board[N+1][M+1];

    char input;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            std::cin >> input;
            board[i][j] = input;
        }
    }

    char start;
    std::vector<int> result;
    for(int i = 0; i <= N-8; i++){
        for(int j = 0; j <= M-8; j++){
            int cnt = 0;
            start = 'B';
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    if(k % 2 == 0 || k == 0){
                        if((l % 2 == 0 || l == 0) && board[i+k][j+l] != start)
                            cnt++;
                        if(l % 2 == 1 && board[i+k][j+l] == start)
                            cnt++;
                    }
                    else{
                        if((l % 2 == 0 || l == 0) && board[i+k][j+l] == start)
                            cnt++;
                        if(l % 2 == 1 && board[i+k][j+l] != start)
                            cnt++;
                    }
                }
            }
            result.push_back(cnt);
            cnt = 0;
            start = 'W';
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    if(k % 2 == 0 || k == 0){
                        if((l % 2 == 0 || l == 0) && board[i+k][j+l] != start)
                            cnt++;
                        if(l % 2 == 1 && board[i+k][j+l] == start)
                            cnt++;
                    }
                    else{
                        if((l % 2 == 0 || l == 0) && board[i+k][j+l] == start)
                            cnt++;
                        if(l % 2 == 1 && board[i+k][j+l] != start)
                            cnt++;
                    }
                }
            }
            result.push_back(cnt);
        }
    }
    std::sort(result.begin(), result.end());
    std::cout << *result.begin();
}