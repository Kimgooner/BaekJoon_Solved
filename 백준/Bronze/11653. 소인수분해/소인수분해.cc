#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if(N != 1) {
        while (true) {
            bool isDo = false;
            for(int i = 2; i < N; i++){
                if(N % i == 0){
                    std::cout << i << "\n";
                    N = N / i;
                    isDo = true;
                    break;
                }
            }
            if(!isDo) {
                std::cout << N;
                break;
            }
        }
    }
}