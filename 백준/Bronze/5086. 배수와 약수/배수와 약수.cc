#include <iostream>

int main() {
    int A, B;
    while(1){
        std::cin >> A >> B;
        if (A > B) {
            if (A % B != 0)
                std::cout << "neither";
            else {
                std::cout << "multiple";
            }
        }
        else if (B > A){
            if (B % A != 0)
                std::cout << "neither";
            else
                std::cout << "factor";
        }
        if (A == 0 && B == 0)
            break;
        else
            std::cout << "\n";
    }
}