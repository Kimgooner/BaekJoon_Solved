#include <iostream>

int board[2005][2005];

int M, N, K;

int main() {
    std::cin >> M >> N >> K;

    char input;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            std::cin >> input;
            if((i+j) % 2 == 0){
                if(input == 'B') board[i][j] = 0;
                else board[i][j] = 1;
            }
            else{
                if(input == 'B') board[i][j] = 1;
                else board[i][j] = 0;
            }
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
        }
    }

    /*
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
     */

    int res = 4000000;
    for(int i = 1; i <= M-K+1; i++){
        for(int j = 1; j <= N-K+1; j++){
            int B = board[i+K-1][j+K-1] - (board[i-1][j+K-1] + board[i+K-1][j-1] - board[i-1][j-1]);
            int W = (K*K) - B;
            res = std::min(res, std::min(B, W));
        }
    }
    std::cout << res;
}