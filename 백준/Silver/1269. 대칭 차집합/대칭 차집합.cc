#include <iostream>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B;
    std::cin >> A >> B;
    std::map<int,int> nums;
    int input;
    while(A--){
        std::cin >> input;
        nums[input]++;
    }
    while(B--){
        std::cin >> input;
        nums[input]++;
    }

    int cnt = 0;
    for(auto& iter : nums){
        if(iter.second == 1){
            cnt++;
        }
    }
    std::cout << cnt;
}
