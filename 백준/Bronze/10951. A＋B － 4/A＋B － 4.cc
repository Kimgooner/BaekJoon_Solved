#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int A, B;
    while(std::cin >> A >> B) {
        std::cout << A+B << "\n";
    }
}