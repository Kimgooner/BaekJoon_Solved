#include <iostream>
#include <algorithm>

int main() {
    std::string num;
    bool isQuit = false;
    while (!isQuit) {
        std::cin >> num;
        if (num.size() == 1) {
            if (num == "0") {
                isQuit = true;
                break;
            } else {
                std::cout << "yes\n";
                continue;
            }
        }
        std::string num2 = num;
        std::reverse(num2.begin(), num2.end());
        
        if(num == num2)
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
}