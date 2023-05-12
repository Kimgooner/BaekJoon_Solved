#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int,int>& p1, std::pair<int,int>& p2){
    if(p1.first < p2.first) return true;
    else return false;
}

int main() {
    int N, K, W, V;
    std::vector<std::pair<int,int>> stuffs;
    std::cin >> N >> K;
    for(int i = 0; i < N; i++){
        std::cin >> W >> V;
        stuffs.emplace_back(W,V);
    }
    std::sort(stuffs.begin(), stuffs.end(), cmp);
    int result[K+1];
    for(auto &iter : result)
        iter = 0;

    for(auto &iter : stuffs){
        for(int i = K; i >= 0; i--){
            if(i >= iter.first){
                if(result[i] <= result[i - iter.first] + iter.second)
                    result[i] = result[i - iter.first] + iter.second;
                if(result[i] < iter.second)
                    result[i] = iter.second;
            }
        }
    }
    int max = 0;
    for(auto iter : result) {
        if (iter > max)
            max = iter;
    }
    std::cout << max;
}