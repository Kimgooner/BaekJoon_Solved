#include <iostream>
#include <algorithm>

int N;
std::pair<int, int> wire[105];
int dp[505];

bool cmp(std::pair<int,int> a, std::pair<int, int> b){
    if(a.first < b.first) return true;
    else return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        std::cin >> a >> b;
        wire[i] = std::pair<int,int>(a,b);
    }
    std::sort(wire, wire+N, cmp);
    int res = 0;
    for(int i = 0; i < N; i++){
        int num = wire[i].second;
        int max = 0;
        for(int j = 0; j < num; j++){
            if(max < dp[j]) max = dp[j];
        }
        dp[num] = max + 1;
        if(res < dp[num]) res = dp[num];
    }

    std::cout << N - res;
}