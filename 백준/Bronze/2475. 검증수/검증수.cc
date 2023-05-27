#include <iostream>

int main() {
    int sum = 0;
    int input;

    for(int i = 0 ; i < 5; i++){
        std::cin >> input;
        sum += input*input;
    }
    std::cout << sum % 10;
}