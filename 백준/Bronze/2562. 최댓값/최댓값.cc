#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int input;
    std::vector<int> arr;
    for(int i = 0; i < 9; i++){
        std::cin >> input;
        arr.push_back(input);
    }

    int max = *std::max_element(arr.begin(), arr.end());
    int max_pos = std::max_element(arr.begin(), arr.end()) - arr.begin();

    std::cout << max << "\n" << max_pos+1;
}
