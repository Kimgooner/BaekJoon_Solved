#include <iostream>
#include <vector>
#include <algorithm>

int N,M;
std::vector<int> nums;

int binary_search(int n, int start, int end){
    int pivot = start + (end-start)/2;
    if(start > end) return 0;

    if(n == nums[pivot]) return 1;
    else if (n < nums[pivot]) {
        return binary_search(n, start, pivot-1);
    }
    else {
        return binary_search(n, pivot+1, end);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    int input;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        nums.push_back(input);
    }
    std::sort(nums.begin(), nums.end());
    std::cin >> M;
    for(int i = 0; i < M; i++){
        std::cin >> input;
        std::cout << binary_search(input, 0, (int)nums.size()-1) <<"\n";
    }
}