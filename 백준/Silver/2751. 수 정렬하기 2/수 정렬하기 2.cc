#include <iostream>
#include <vector>
#include <algorithm>
bool cmp (int a, int b){
    if(a < b) return true;
    else return false;
}
int main() {
    int N;
    std::vector<int> nums;
    std::cin >> N;

    int input;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        nums.push_back(input);
    }
    std::sort(nums.begin(), nums.end(), cmp);

    for(int v : nums)
        std::cout << v << "\n";
}