#include <iostream>

int N;
int nums[3000005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    nums[1] = 0;
    nums[2] = 1;
    nums[3] = 1;

    for(int i = 4; i <= 1000000; i++){
        nums[i] = 100000;
    }

    for(int i = 1; i <= 1000000; i++){
        if(nums[i+1] != 0 && nums[i+1] > nums[i] + 1) nums[i+1] = nums[i] + 1;
        if(nums[i*2] != 0 && nums[i*2] > nums[i] + 1) nums[i*2] = nums[i] + 1;
        if(nums[i*3] != 0 && nums[i*3] > nums[i] + 1) nums[i*3] = nums[i] + 1;
    }

    std::cout << nums[N];
}