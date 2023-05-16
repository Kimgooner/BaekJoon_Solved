#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int,int> p1, std::pair<int,int> p2){
    if(p1.first < p2.first) return true;
    else if(p1.first == p2.first){
        if(p1.second < p2.second) return true;
        else return false;
    }
    else return false;
}

int main() {
    int N;
    std::cin >> N;

    int n1, n2;
    std::vector<std::pair<int,int>> nums;
    for(int i = 0; i < N; i++){
        std::cin >> n1 >> n2;
        nums.emplace_back(n1, n2);
    }
    std::sort(nums.begin(), nums.end(), cmp);

    for(std::pair<int,int> p : nums)
        std::cout << p.first << " " << p.second << "\n";
}