#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, input, option;
    std::vector<int> arr;
    std::cin >> N >> option;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        if(input < option)
            arr.push_back(input);
    }
    for(const auto& iter : arr){
        std::cout << iter << " ";
    }
}
