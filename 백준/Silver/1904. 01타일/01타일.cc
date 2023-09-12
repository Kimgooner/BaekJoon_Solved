#include <iostream>

int bin[1000005];

int main() {
    bin[1] = 1;
    bin[2] = 2;
    for(int i = 3; i <= 1000000; i++){
        bin[i] = (bin[i-1] + bin[i-2]) % 15746;
    }

    int N;
    std::cin >> N;
    std::cout << bin[N];
}