#include <iostream>

int main() {
    int matrix[9][9];
    std::pair<int,int> pos;
    int max = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            std::cin >> matrix[i][j];
            if(matrix[i][j] >= max) {
                max = matrix[i][j];
                pos = {i+1, j+1};
            }
        }
    }
    std::cout << max  << "\n" << pos.first << " " << pos.second;
}