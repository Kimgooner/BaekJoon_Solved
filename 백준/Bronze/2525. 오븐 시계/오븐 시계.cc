#include <iostream>

int main() {
    int H, M, T, hr, min;
    std::cin >> H >> M >> T;
    hr = (T / 60) % 24;
    min = T % 60;
    if((M + min) >= 60) {
        hr++;
        M = (M + min) - 60;
        if((H + hr) >= 24)
            H = (H + hr) - 24;
        else
            H = H + hr;
    }
    else {
        M = M + min;
        if((H + hr) >= 24)
            H = (H + hr) - 24;
        else
            H = H + hr;
    }

    std::cout << H << " " << M;
}