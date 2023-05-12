#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, input;
    std::vector<int> arr;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        arr.push_back(input);
    }

    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());

    std::cout << min << " " << max;

}
