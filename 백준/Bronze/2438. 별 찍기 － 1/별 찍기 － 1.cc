#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i+1; j++){
            std::cout << "*";
        }
        std::cout << "\n";
    }
}