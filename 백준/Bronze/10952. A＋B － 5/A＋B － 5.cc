#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int A, B;
    bool isQuit = false;
    while(!isQuit) {
        std::cin >> A >> B;
        if(A == 0 && B == 0) {
            isQuit = true;
            continue;
        }
        else {
            std::cout << A+B << "\n";
        }
    }
}