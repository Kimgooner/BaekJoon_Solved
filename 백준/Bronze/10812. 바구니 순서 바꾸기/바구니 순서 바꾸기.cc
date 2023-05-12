#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> basket;

    for(int i = 0; i < N; i++)
        basket.push_back(i + 1);

    int i, j, k;
    for(int l = 0; l < M; l++){
        std::vector<int> tmp;
        std::cin >> i >> j >> k;

        for(int m = k-1; m < j; m++){
            tmp.push_back(basket[m]);
        }

        for(int m = i-1; m < k-1; m++){
            tmp.push_back(basket[m]);
        }

        int idx = 0;
        for(int m = i-1; m <= j-1; m++){
            basket[m] = tmp[idx++];
        }
    }
    for(int& val : basket)
        std::cout << val << " ";
}