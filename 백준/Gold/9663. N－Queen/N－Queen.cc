#include <iostream>
#include <algorithm>

int N, cnt = 0;
int board[15] = {0, };

void dfs(int n){
    if(n == N) cnt++;
    else {
        for(int i = 0; i < N; i++){
            bool isCorrect = true;
            board[n] = i;
            for(int j = 0; j < n; j++){
                int diff_1 = n - j;
                int diff_2 = board[n] - board[j];
                if(diff_2 < 0)
                    diff_2 = -1 * diff_2;
                if(diff_1 == diff_2) {
                    isCorrect = false;
                    break;
                }
                if(board[n] == board[j]){
                    isCorrect = false;
                    break;
                }
            }
            if(isCorrect)
                dfs(n + 1);
            board[n] = 0;
        }
    }
}

int main() {
    std::cin >> N;
    dfs(0);
    std::cout << cnt;
}