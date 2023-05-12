#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int T, A, B;
    std::cin >> T;
    for(int i = 0; i < T; i++){
        std::cin >> A >> B;
        std::cout << "Case #" << (i+1) << ": " << A+B << "\n";
    }
}