#include <iostream>
int N, M;
long long int pre_sum[1000005];
long long int nums_cnt[1005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    int input;
    for(int i = 1; i <= N; i++){
        std::cin >> input;
        pre_sum[i] = (pre_sum[i-1] + input) % M;
        nums_cnt[pre_sum[i]]++;
    }

    long long res = nums_cnt[0];
    for(int i = 0; i < M; i++){
        res += (nums_cnt[i] * (nums_cnt[i]-1)) / 2;
    }
    std::cout << res;
}