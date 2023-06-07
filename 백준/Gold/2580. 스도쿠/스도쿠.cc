#include <iostream>
#include <vector>

int sudoku[9][9];
bool flag;
int row, col;
std::vector<std::pair<int,int>> vec;

void dfs(int n) {
    if(n == vec.size()) {
        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << sudoku[i][j] << " ";
            }
            std::cout << "\n";
        }
        exit(0);
    }
    else {
        for(int num = 1; num < 10; num++){
            flag = true;
            for(int k = 0; k < 9; k++){
                if(num == sudoku[vec[n].first][k] || num == sudoku[k][vec[n].second]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                row = vec[n].first / 3 * 3;
                col = vec[n].second / 3 * 3;
                for(int k = row; k < row + 3; k++){
                    for(int m = col; m < col + 3; m++){
                        if(num == sudoku[k][m]){
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(flag){
                sudoku[vec[n].first][vec[n].second] = num;
                dfs(n+1);
                sudoku[vec[n].first][vec[n].second] = 0;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int input;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            std::cin >> input;
            sudoku[i][j] = input;
            if(input == 0) {
                vec.emplace_back(i,j);
            }
        }
    }
    dfs(0);
}