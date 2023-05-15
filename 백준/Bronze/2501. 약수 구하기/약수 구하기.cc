#include <iostream>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> result;

    int idx = 1;
    while(N >= idx){
        if(N % idx == 0)
            result.push_back(N / idx);
        idx++;
    }
    if(K > result.size())
        std::cout << 0;
    else
        std::cout << result[result.size()-K];
}
