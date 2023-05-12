#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string str;
    std::getline(std::cin, str);

    int cnt = 1;
    for(char c : str){
        if(std::isspace(c))
            cnt++;
    }
    if(std::isspace(str[0]))
        cnt--;
    if(std::isspace(str[str.size()-1]))
        cnt--;
    std::cout << cnt;
}