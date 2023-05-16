#include <iostream>
#include <iomanip>

int main() {
    double N;
    std::cin >> N;

    std::cout << std::fixed << std::setprecision(0);
    std::cout << N*(N-1)*0.5 << "\n" << 2;
}
