#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, k, input;
    std::cin >> N >> k;

    std::vector<int> grade;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        grade.push_back(input);
    }
    std::sort(grade.begin(), grade.end());
    std::cout << *(grade.end()-k);
}