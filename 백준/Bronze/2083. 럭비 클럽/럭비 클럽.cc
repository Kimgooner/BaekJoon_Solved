#include <iostream>

int main() {
    std::string name;
    int age, kg;

    while(true) {
        std::cin >> name >> age >> kg;
        if(name == "#" && age == 0 && kg == 0)
            break;
        else {
            if(age > 17 || kg >= 80){
                std::cout << name << " Senior\n";
            }
            else
                std::cout << name << " Junior\n";
        }
    }
}