#include <iostream>

int main() {
    int A;
    std::cin >> A;
    
    if(A >= 90)
        std::cout << "A";
    else if(90 > A && A >= 80)
        std::cout << "B";
    else if(80 > A && A >= 70)
        std::cout << "C";
    else if(70 > A && A >= 60)
        std::cout << "D";
    else
        std::cout << "F";
}