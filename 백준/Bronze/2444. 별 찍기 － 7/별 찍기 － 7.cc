#include <iostream>

int main() {
    int N;
    std::cin >> N;
    for(int i = 1; i < (2*N); i++) {
        if (i < N) {
            for (int j = 1; j < 2 * N; j++) {
                if(j > N-i && j < N+i)
                    std::cout << "*";
                else if(j <= N-i)
                    std::cout << " ";
                else
                    break;
            }
            std::cout << std::endl;
        }
        else if(i == N) {
            for (int j = 1; j < 2 * N; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        else {
            for (int j = 1; j < 2 * N; j++) {
                if(j > i-N && j < (3*N)-i)
                    std::cout << "*";
                else if(j <= i-N)
                    std::cout << " ";
                else
                    break;
            }
            if(i < (2*N)-1)
                std::cout << std::endl;
        }
    }
}