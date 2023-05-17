#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int input;
    int* cards = new int[21000000];
    int N;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        cards[input+10000000]++;
    }

    int M;
    std::cin >> M;
    std::vector<int> cards_2;
    for(int i = 0; i < M; i++){
        std::cin >> input;
        std::cout << cards[input+10000000] << " ";
    }
}