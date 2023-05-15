#include <iostream>

int main() {
    int A, B, V;
    std::cin >> A >> B >> V;

    int mov = A - B;
    int dist = V - A;

    if(dist % mov == 0)
        std::cout << (dist / mov) + 1;
    else if(dist % mov > 0)
        std::cout << (dist / mov) + 2;
}