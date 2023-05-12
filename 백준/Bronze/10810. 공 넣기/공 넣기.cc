#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    int* basket = new int[N+1];

    int i, j, k;
    for(int idx1 = 0; idx1 < M; idx1++){
        std::cin >> i >> j >> k;
        for(int idx2 = i; idx2 <= j; idx2++){
            basket[idx2] = k;
        }
    }

    for(int idx = 1; idx <= N; idx++)
        std::cout << basket[idx] << " ";
}
