#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> measures;
    int measure;
    for(int i = 0; i < N; i++){
        std::cin >> measure;
        measures.push_back(measure);
    }
    std::sort(measures.begin(), measures.end());

    if(N % 2 == 0)
        std::cout << measures[0] * measures[measures.size()-1];
    else
        std::cout << measures[measures.size() / 2] * measures[measures.size() / 2];
}