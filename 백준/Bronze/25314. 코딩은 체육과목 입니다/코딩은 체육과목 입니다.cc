#include <iostream>

int main() {
    int N, cnt;
    std::cin >> N;
    cnt = N / 4;

    for(int i = 0; i < cnt; i++){
        std::cout << "long ";
    }
    std::cout << "int";
}