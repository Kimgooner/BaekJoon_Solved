#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int,int>& p1, std::pair<int,int>& p2){
    if(p1.second > p2.second) return true;
    else return false;
}

int main() {
    char str[1000100] = {};
    std::vector<std::pair<int,int>> alphabet;
    std::cin >> str;

    for(int i = 0; i < 26; i++)
        alphabet.emplace_back(i, 0);

    for(char c : str){
        if(c >= 'A' && 'Z' >= c)
            alphabet[c-'A'].second++;
        else if(c >= 'a' && 'z' >= c)
            alphabet[c-'a'].second++;
    }

    std::sort(alphabet.begin(), alphabet.end(), cmp);

    if(alphabet[0].second == alphabet[1].second)
        std::cout << "?";
    else
        std::cout << static_cast<char>(alphabet[0].first+'A');
}
