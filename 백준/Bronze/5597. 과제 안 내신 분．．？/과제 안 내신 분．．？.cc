#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::vector<int> vec;
    for(int i = 1; i < 31; i++){
        vec.push_back(i);
    }

    int find;
    for(int i = 0; i < 28; i++){
        std::cin >> find;
        for(auto& iter : vec) {
            if (iter == find)
                iter = 0;
        }
    }

    for(const auto& iter : vec) {
        if (iter != 0)
            std::cout << iter << "\n";
    }
}