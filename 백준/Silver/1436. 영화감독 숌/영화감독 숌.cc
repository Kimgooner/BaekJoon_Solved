#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int l = 0; l < 10; l++){
                    int num1 = 666 + 1000*l + 10000*k + 100000*j + 1000000*i;
                    int num2 = 6660 + 1*l + 10000*k + 100000*j + 1000000*i;
                    int num3 = 66600 + 1*l + 10*k + 100000*j + 1000000*i;
                    int num4 = 666000 + 1*l + 10*k + 100*j + 1000000*i;
                    int num5 = 6660000 + 1*l + 10*k + 100*j + 1000*i;
                    nums.push_back(num1);
                    nums.push_back(num2);
                    nums.push_back(num3);
                    nums.push_back(num4);
                    nums.push_back(num5);
                }
            }
        }
    }
    std::sort(nums.begin(), nums.end());
    auto find = std::unique(nums.begin(), nums.end());
    nums.erase(find, nums.end());

    int N;
    std::cin >> N;
    std::cout << nums[N-1];
}