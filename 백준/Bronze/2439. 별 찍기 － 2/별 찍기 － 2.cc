#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            if(j < i)
                std::cout << " ";
            else
                std::cout << "*";
        }
        std::cout << "\n";
    }
}