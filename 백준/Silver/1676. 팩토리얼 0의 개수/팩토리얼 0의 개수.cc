#include <iostream>

int count_2[501];
int count_5[501];
int N;

int main(){
    std::cin >> N;
    for(int i = 1; i <= 500; i++){
        count_2[i] = count_2[i-1];
        count_5[i] = count_5[i-1];
        if(i % 2 == 0){
            int val = i;
            while(val % 2 == 0){
                val /= 2;
                count_2[i]++;
            }
        }
        if(i % 5 == 0){
            int val = i;
            while(val % 5 == 0){
                val /= 5;
                count_5[i]++;
            }
        }
    }
    if(count_2[N] >= 1 && count_5[N] >= 1) std::cout << std::min(count_2[N], count_5[N]);
    else std::cout << 0;
}