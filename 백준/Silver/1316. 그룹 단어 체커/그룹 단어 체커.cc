#include <iostream>

int main() {
    int N;
    std::cin >> N;

    std::string str;
    int cnt = N;
    for(int i = 0; i < N; i++){
        int alphabet[26] = {0, };
        std::cin >> str;
        for(char c : str)
            alphabet[c-'a']++;

        for(int j = 0; j < str.size(); j++){
            alphabet[str[j]-'a'] -= 1;
            if(j < str.size()-1){
                if(str[j] != str[j+1] && alphabet[str[j]-'a'] != 0) {
                    cnt -= 1;
                    break;
                }
            }
        }
    }
    std::cout << cnt;
}
