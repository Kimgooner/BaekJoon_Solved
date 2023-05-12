#include <iostream>
#include <iomanip>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;
    std::cout << std::fixed << std::setprecision(0);
    std::cout << A + B + C;
}