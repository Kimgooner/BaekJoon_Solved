#include <iostream>

int main(){
    std::string ascend = "12345678";
    std::string descend = "87654321";

    char tune[9];
    for(int i = 0; i < 8; i++){
        std::cin >> tune[i];
    }
    tune[8] = '\0';
    if(tune == ascend) std::cout << "ascending";
    else if(tune == descend) std::cout << "descending";
    else std::cout << "mixed";
}