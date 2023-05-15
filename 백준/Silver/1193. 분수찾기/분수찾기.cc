#include <iostream>
#include <vector>

int main() {
    std::vector<int> chart;

    int T = 1, idx = 2;
    while(1){
        chart.push_back(T);
        T = T + idx;
        idx++;
        if(T > 10000000){
            chart.push_back(T);
            break;
        }
    }

    int N;
    std::cin >> N;
    if(N == 1)
        std::cout << "1/1";
    else {
        for(int i = 0; i < chart.size()-1; i++){
            if((N > chart[i] && chart[i+1] >= N) && i % 2 == 0) {
                int lhs = 1;
                int rhs = i + 2;
                int diff = N - (chart[i] + 1);
                std::cout << lhs + diff << "/" << rhs - diff;
                break;
            }
            else if((N > chart[i] && chart[i+1] >= N) && i % 2 == 1) {
                int lhs = i + 2;
                int rhs = 1;
                int diff = N - (chart[i] + 1);
                std::cout << lhs - diff << "/" << rhs + diff;
                break;
            }
        }
    }
}