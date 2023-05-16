#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int origin = N;

    int cnt = 0;
    while(N > 4) {
        N -= 5;
        cnt++;
    }

    while(true) {
        if (N > origin) {
            std::cout << -1;
            break;
        }
        else if (N % 3 != 0) {
            N += 5;
            cnt--;
        }
        else {
            std::cout << cnt + (N/3);
            break;
        }
    }
}