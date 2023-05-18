#include <iostream>
#include <vector>
#include <algorithm>

int Euclidean(int a, int b){
    int r = a % b;
    if(r == 0)
        return b;
    return Euclidean(b, r);
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> lamp;
    std::vector<int> dist;
    int input;
    while(N--){
        std::cin >> input;
        lamp.push_back(input);
    }
    for(int i = 0; i < lamp.size()-1; i++){
        dist.push_back(lamp[i+1] - lamp[i]);
    }
    std::sort(dist.begin(), dist.end());
    int max_div;
    for(auto iter = dist.begin(); iter != dist.end(); iter++){
        if(iter == dist.begin())
            max_div = *iter;
        else
            max_div = Euclidean(max_div, *iter);
    }

    int sum = 0;
    for(int v : dist){
        sum += (v / max_div) - 1;
    }
    std::cout << sum;
}