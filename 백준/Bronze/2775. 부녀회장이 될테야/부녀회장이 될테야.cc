#include <iostream>

int T, k, n;
int ppl[15][15];

/*
 * 1 2 3 4
 * 1 3 6 10
 * 1 4 10 20
 * 1 5 15 35
 */

int main(){
    for(int i = 1; i <= 14; i++){
        ppl[0][i] = i;
    }
    std::cin >> T;

    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            ppl[i][j] = ppl[i][j-1] + ppl[i-1][j];
        }
    }
    while(T--){
        std::cin >> k >> n;
        std::cout << ppl[k][n] << "\n";
    }
}