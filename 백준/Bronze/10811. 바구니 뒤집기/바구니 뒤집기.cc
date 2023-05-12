#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> basket;

    for(int idx = 1; idx < N+1; idx++){
        basket.push_back(idx);
    }

    int i, j, front_idx, back_idx;
    for(int rep = 0; rep < M; rep++){
        std::cin >> i >> j;
        front_idx = i-1;
        back_idx = j-1;
        for(int idx = front_idx; idx <= back_idx; idx++){
            int tmp = basket[idx];
            basket[idx] = basket[back_idx];
            basket[back_idx--] = tmp;
        }
    }
    for(const auto& iter : basket)
        std::cout << iter << " ";
}