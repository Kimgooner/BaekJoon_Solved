#include <iostream>

int paper[130][130];
int N;
int count = 0, count_blue = 0;

bool check(int pos_x, int pos_y, int size){
    int std_val = paper[pos_x][pos_y];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(paper[pos_x+i][pos_y+j] != std_val) return false;
        }
    }
    if(std_val == 1) count_blue++;
    count++;
    return true;
}

void divide(int pos_x, int pos_y, int size){
    if(!check(pos_x, pos_y, size)){
        divide(pos_x, pos_y, size/2);
        divide(pos_x+size/2, pos_y, size/2);
        divide(pos_x, pos_y+size/2, size/2);
        divide(pos_x+size/2, pos_y+size/2, size/2);
    }
}



int main() {
    std::cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> paper[i][j];
        }
    }
    divide(0,0,N);
    std::cout << count - count_blue << "\n";
    std::cout << count_blue;
}