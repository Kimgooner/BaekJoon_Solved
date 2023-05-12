#include <iostream>

int main() {
    int A, B;
    int res1, res2, res3;
    std::cin >> A >> B;
    res1 = A * (B % 10);
    res2 = A * ((B % 100) / 10);
    res3 = A * (B / 100);
    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    std::cout << res3 << std::endl;
    std::cout << res1 + (10 * res2) + (100 * res3);
}