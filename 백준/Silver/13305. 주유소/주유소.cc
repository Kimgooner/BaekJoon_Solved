#include <iostream>

long long length[1000005];
long long cost[1000005];
int N;

int main() {
    std::cin >> N;

    for(int i = 0; i < N-1; i++){
        std::cin >> length[i];
    }

    for(int i = 0; i < N; i++){
        std::cin >> cost[i];
    }

    long long total_cost = 0;
    long long cur_cost = 10000000000;
    for(int i = 0; i < N-1; i++){
        cur_cost = std::min(cur_cost, cost[i]);
        total_cost += cur_cost * length[i];
    }
    std::cout << total_cost;
}