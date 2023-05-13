#include <iostream>
#include <vector>

int main() {
    char arr[5][15] = {};
    std::vector<char> result;
    for(int i = 0; i < 5; i++){
        std::cin >> arr[i];
    }

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            char cur = arr[j][i];
            if((cur >= 'a' && 'z' >= cur) || (cur >= 'A' && 'Z' >= cur) || (cur >= '0' && '9' >= cur))
                result.push_back(cur);
        }
    }
    for(char c : result)
        std::cout << c;
}