#include <iostream>

int N;
int nums[50005];

int main() {
    std::cin >> N;
    for(int i = 1; i <= 50000; i++){
        nums[i] = i;
    }

    for(int i = 2; i*i <= 50000; i++){
        nums[i*i] = 1;
        for(int j = 1; j+(i*i) <= 50000; j++){
            if(nums[j+(i*i)] > nums[j] + 1){
                nums[j+(i*i)] = nums[j] + 1;
            }
        }
    }

    std::cout << nums[N];
}