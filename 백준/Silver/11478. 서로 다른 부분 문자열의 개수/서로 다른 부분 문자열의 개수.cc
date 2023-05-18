#include <iostream>
#include <map>
#include <cstring>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char* str = new char[2000];
    std::cin >> str;
    int size = strlen(str);
    std::map<std::string, int> lst;

    char* new_str = new char[2000];
    for(int i = 1; i <= size; i++){
        for(int j = 0; j <= size-i; j++){
            std::copy(str+j, str+j+i, new_str);
            new_str[j+i] = '\0';
            lst[new_str]++;
        }
    }
    int cnt = 0;
    for(auto& iter : lst){
        if(iter.second >= 1)
            cnt++;
    }
    std::cout << cnt;
}