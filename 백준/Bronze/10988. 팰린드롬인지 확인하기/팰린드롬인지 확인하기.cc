#include <iostream>

int main() {
    std::string str;
    std::cin >> str;

    int result = 1;

    if(str.size() % 2 == 0) {
        for(int i = 0; i < str.size()/2; i++){
            if(str[i] != str[(str.size()-1)-i]) {
                result = 0;
            }
        }
    }
    else {
        for(int i = 0; i < str.size()/2; i++){
            if(str[i] != str[(str.size()-1)-i]){
                result = 0;
            }
        }
    }
    std::cout << result;
}