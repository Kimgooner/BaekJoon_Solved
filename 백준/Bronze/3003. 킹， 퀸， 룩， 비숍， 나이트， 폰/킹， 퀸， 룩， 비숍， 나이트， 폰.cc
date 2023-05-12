#include <iostream>

int main() {
    int chess[6] = {1, 1, 2, 2, 2, 8};
    int input, idx = 0;

    for(int i : chess){
        std::cin >> input;
        chess[idx++] = i - input;
    }

    for(int i : chess) {
        std::cout << i << " ";
    }
}
