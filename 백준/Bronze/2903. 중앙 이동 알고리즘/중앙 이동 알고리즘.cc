#include <iostream>

int main() {
    int N;
    int cur = 4, cur_line = 2;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        cur = (cur * 4) - 2 *((2 * cur_line) - 1) - 1;
        cur_line = (2 * cur_line) - 1;
    }
    std::cout << cur;
}