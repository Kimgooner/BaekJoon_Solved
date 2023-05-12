#include <iostream>

int main() {
    int X, Y;
    std::cin >> X >> Y;
    if(X > 0) {
        if(Y > 0)
            std::cout << 1;
        else
            std::cout << 4;
    }
    else {
        if(Y > 0)
            std::cout << 2;
        else
            std::cout << 3;
    }
}