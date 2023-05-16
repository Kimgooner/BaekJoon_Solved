#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::string &s1, std::string &s2){
    if(s1.size() < s2.size()) return true;
    else if(s1.size() == s2.size())
        if(s1 < s2) return true;
        else return false;
    else return false;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> words;
    std::string input;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        words.push_back(input);
    }
    std::sort(words.begin(), words.end(), cmp);
    auto find = std::unique(words.begin(), words.end());
    words.erase(find, words.end());

    for(std::string& s : words)
        std::cout << s << "\n";
}