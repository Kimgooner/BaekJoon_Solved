#include <iostream>
#include <vector>

int main() {
    std::vector<int> honeycomb;

    int T = 1, idx = 1;
    while(1){
        honeycomb.push_back(T);
        T = T + (6 * idx);
        idx++;
        if(T > 1000000000) {
            honeycomb.push_back(T);
            break;
        }
    }
    int N;
    std::cin >> N;
    if(N == 1)
        std::cout << 1;
    else {
        for (int i = 0; i < honeycomb.size() - 1; i++) {
            if (N > honeycomb[i] && honeycomb[i + 1] >= N) {
                std::cout << i + 2;
                break;
            }
        }
    }
}