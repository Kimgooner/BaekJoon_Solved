#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

bool cmp(int a, int b){
    if(a > b) return true;
    else return false;
}

int main() {
    std::cout << std::fixed << std::setprecision(3);
    int C, N, input;
    std::cin >> C;

    for(int i = 0; i < C; i++){
        std::vector<int> grade;
        std::cin >> N;
        double sum = 0;
        int cnt = 0;

        for(int j = 0; j < N; j++){
            std::cin >> input;
            grade.push_back(input);
            sum += input;
        }

        std::sort(grade.begin(), grade.end(), cmp);
        double avg = sum / N;

        for(int v : grade){
            if(v > avg)
                cnt++;
            else
                break;
        }
        std::cout << ((double)cnt / N)*100 << "%\n";
    }
}