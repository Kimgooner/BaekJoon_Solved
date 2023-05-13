#include <iostream>

int main() {
    int N;
    int paper[100][100] = {0};
    std::cin >> N;

    int n1, n2;
    for(int i = 0; i < N; i++){
        std::cin >> n1 >> n2;
        for(int j = n1; j < n1+10; j++){
            for(int k = n2; k < n2+10; k++){
                paper[j][k] = 1;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            sum += paper[i][j];
        }
    }
    std::cout << sum;
}