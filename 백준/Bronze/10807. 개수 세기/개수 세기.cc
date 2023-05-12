#include <iostream>
#include <vector>

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

    int find_num, cnt = 0;
    std::cin >> find_num;

    for(const auto& iter : arr){
        if(iter == find_num)
            cnt++;
    }
    std::cout << cnt;
}