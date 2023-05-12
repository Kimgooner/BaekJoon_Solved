#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    double input;
    std::vector<double> grade;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> input;
        grade.push_back(input);
    }
    std::sort(grade.begin(), grade.end());
    double max = *(grade.end() - 1);

    double sum = 0;
    for (auto iter = grade.begin(); iter != grade.end(); iter++) {
        sum += *iter/max*100;
    }
    std::cout << std::fixed << std::setprecision(6);
    std::cout << sum / static_cast<double>(grade.size());
}