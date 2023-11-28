#include <iostream>

int N;
int paper[2200][2200];
int count1 = 0, count2 = 0, count3 = 0;

bool check(int pos_y, int pos_x, int size){
    int pivot = paper[pos_y][pos_x];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(pivot != paper[pos_y+i][pos_x+j]) return false;
        }
    }
    if(pivot == -1) count1++;
    else if(pivot == 0) count2++;
    else count3++;
    return true;
}

void divide(int pos_y, int pos_x, int size){
    if(!check(pos_y,pos_x,size)){
        int new_size = size/3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                divide(pos_y+(i*new_size),pos_x+(j*new_size),new_size);
            }
        }
    }
}

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> paper[i][j];
        }
    }
    divide(0,0,N);
    std::cout << count1 << "\n" << count2 << "\n" << count3;
}