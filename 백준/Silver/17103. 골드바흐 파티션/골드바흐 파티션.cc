#include <iostream>

int main() {
    int* nums = new int[1000001];
    for(int i = 2; i <= 1000000; i++){
        if(nums[i] == 1) continue;
        for(int j = 2*i; j <= 1000000; j+=i){
            nums[j] = 1;
        }
    }

    int N;
    std::cin >> N;

    int input;
    while(N--) {
        std::cin >> input;

        int cnt = 0;
        for(int i = 2; i <= input / 2; i++){
            if(nums[i] == 0 && nums[input-i] == 0)
                cnt++;
        }
        std::cout << cnt << "\n";
    }
}