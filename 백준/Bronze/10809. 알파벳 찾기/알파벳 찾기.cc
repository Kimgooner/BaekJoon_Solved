#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int* alphabet = new int[26];
    for(int i = 0; i < 26; i++){
        alphabet[i] = -1;
    }

    std::string str;
    std::cin >> str;

    int index = 0;
    for(const auto& iter : str){
        if(alphabet[iter - 97] == -1)
            alphabet[iter - 97] = index++;
        else {
            index++;
            continue;
        }
    }
    for(int i = 0; i < 26; i++){
        std::cout << alphabet[i] << " ";
    }
}