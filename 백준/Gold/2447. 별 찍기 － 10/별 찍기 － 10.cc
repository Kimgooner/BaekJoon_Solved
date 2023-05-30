#include <iostream>

void print_star(int row, int col, int N){
    if((row / N) % 3 == 1 && (col / N) % 3 == 1)
        std::cout << ' ';
    else
        if((N / 3) == 0)
            std::cout << '*';
        else
            print_star(row, col, N/3);
}

int main() {
    int N;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            print_star(i, j, N);
        }
        std::cout << '\n';
    }
}
