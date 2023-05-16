#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int input;
    std::vector<int> arr;
    for(int i = 0; i < 5; i++){
        std::cin >> input;
        arr.push_back(input);
    }
    std::sort(arr.begin(), arr.end());
    int sum = std::accumulate(arr.begin(), arr.end(), 0);

    std::cout << sum/(arr.size()) << "\n" << arr[arr.size()/2];
}