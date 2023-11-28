#include <iostream>

int paper[70][70];
int N;

bool check(int pos_x, int pos_y, int size){
    int std_val = paper[pos_x][pos_y];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(paper[pos_x+i][pos_y+j] != std_val) return false;
        }
    }
    std::cout << std_val;
    return true;
}

void divide(int pos_x, int pos_y, int size){
    if(!check(pos_x, pos_y, size)){
        std::cout << "(";
        divide(pos_x, pos_y, size/2);
        divide(pos_x, pos_y+size/2, size/2);
        divide(pos_x+size/2, pos_y, size/2);
        divide(pos_x+size/2, pos_y+size/2, size/2);
        std::cout << ")";
    }
}

int main() {
    std::cin >> N;
    std::string input;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        for(int j = 0; j < N; j++){
            paper[i][j] = input[j] - '0';
        }
    }
    divide(0,0,N);
}