#include <iostream>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int input;
    std::map<int, int> cards;

    while(N--){
        std::cin >> input;
        cards[input]++;
    }

    int M;
    std::cin >> M;
    while(M--){
        std::cin >> input;
        std::cout << cards[input] << " ";
    }
}