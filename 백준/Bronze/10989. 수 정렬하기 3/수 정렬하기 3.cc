#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int data[10001] = {0};

    int input;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        data[input]++;
    }

    for(int i = 1; i < 10001; i++){
        if(data[i] != 0){
            for(int j = 0; j < data[i]; j++){
                std::cout << i << "\n";
            }
        }
    }
}