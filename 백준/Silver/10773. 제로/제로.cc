#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int K;
    std::cin >> K;

    std::vector<int> stack;
    int input;
    while(K--){
        std::cin >> input;
        if(input == 0)
            stack.erase(stack.end()-1);
        else
            stack.push_back(input);
    }
    int ans = std::accumulate(stack.begin(), stack.end(), 0);
    std::cout << ans;
}