#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N;
    while(true){
        std::cin >> N;
        if(N == -1)
            break;
        else {
            std::vector<int> divisor;
            for(int i = 2; i <= N; i++){
                if(N % i == 0)
                    divisor.push_back(N / i);
            }
            std::reverse(divisor.begin(), divisor.end());
            int sum = std::accumulate(divisor.begin(), divisor.end(), 0);
            if(N == sum){
                std::cout << N << " = ";
                for(int i = 0; i < divisor.size(); i++){
                    if(i == divisor.size()-1)
                        std::cout << divisor[i] << "\n";
                    else
                        std::cout << divisor[i] << " + ";
                }
            }
            else
                std::cout << N << " is NOT perfect.\n";
        }
    }
}
