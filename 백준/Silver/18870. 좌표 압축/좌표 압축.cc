#include <iostream>
#include <vector>
#include <algorithm>

int binary_search(int a, std::vector<int>& v, int first, int last){
    int mid = (first + last) / 2;
    if(a == v[mid])
        return mid;
    else if(a < v[mid])
        return binary_search(a, v, first, mid-1);
    else
        return binary_search(a, v, mid+1, last);
}

int main() {
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> nums;
    std::vector<int> nums_sorted;

    int input;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        nums.push_back(input);
    }
    nums_sorted = nums;
    std::sort(nums_sorted.begin(), nums_sorted.end());
    nums_sorted.erase(std::unique(nums_sorted.begin(), nums_sorted.end()), nums_sorted.end());

    for(int v : nums){
        std::cout << binary_search(v, nums_sorted, 0, nums_sorted.size()) << " ";
    }
}