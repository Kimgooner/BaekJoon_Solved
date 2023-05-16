#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int input;
    std::vector<int> arr;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        arr.push_back(input);
    }
    std::sort(arr.begin(), arr.end());
    for(int v : arr){
        std::cout << v << "\n";
    }
}