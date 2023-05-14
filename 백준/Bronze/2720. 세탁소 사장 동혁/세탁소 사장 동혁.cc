#include <iostream>

int main() {
    int T;
    std::cin >> T;

    int input;
    for(int i = 0; i < T; i++){
        std::cin >> input;
        std::cout << input / 25 << " ";
        std::cout << (input % 25) / 10 << " ";
        std::cout << ((input % 25) % 10) / 5 << " ";
        std::cout << (((input % 25) % 10) % 5) / 1 << "\n";
    }
}
