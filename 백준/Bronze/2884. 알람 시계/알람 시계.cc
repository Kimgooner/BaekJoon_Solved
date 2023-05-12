#include <iostream>

int main() {
    int H, M;
    std::cin >> H >> M;
    if(M < 45) {
        if(H == 0)
            H = 23;
        else
            H--;
        M = 60 + (M - 45);
    }
    else
        M = M - 45;
    std::cout << H << " " << M;
}