#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::vector<int> vec;
    std::cin >> N >> M;
    for(int i = 0; i < N; i++){
        vec.push_back(i+1);
    }

    int i, j;
    for(int idx = 0; idx < M; idx++){
        std::cin >> i >> j;
        int tmp = vec[i-1];
        vec[i-1] = vec[j-1];
        vec[j-1] = tmp;
    }

    for(const auto& iter : vec)
        std::cout << iter << " ";
}