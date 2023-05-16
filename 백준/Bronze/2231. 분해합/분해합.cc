#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int result = 0;
    for(int i = 1; i < N; i++){
        int first = i % 10;
        int sum = first;
        for(int j = 10; j <= i; j = j * 10){
            sum += (i / j) - ((i / (j * 10))*10);
        }
        if(sum + i == N) {
            result = i;
            break;
        }
    }
    std::cout << result;
}