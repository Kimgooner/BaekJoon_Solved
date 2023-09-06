#include <iostream>

int fibo[41][2];

int main() {
    int N, input;
    std::cin >> N;

    fibo[0][0] = 1;
    fibo[1][1] = 1;
    for(int i = 2; i < 41; i++){
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }
    for(int i = 0; i < N; i ++){
        std::cin >> input;
        std::cout << fibo[input][0] << " " << fibo[input][1] << std::endl;
    }
}