#include <iostream>
#include <vector>
#include <algorithm>

int N, t;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::vector<int> time;
    for(int i = 0; i < N; i++){
        std::cin >> t;
        time.push_back(t);
    }

    std::sort(time.begin(), time.end());
    int res = 0;
    for(int i = 1; i < N+1; i++){
        res += time[i-1] * ((N+1)-i);
    }
    std::cout << res;
}