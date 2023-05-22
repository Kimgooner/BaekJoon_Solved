#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

bool cmp(std::pair<std::string, int> &p1, std::pair<std::string, int> &p2){
    if(p1.second > p2.second) return true;
    else if(p1.second == p2.second){
        if(p1.first.size() > p2.first.size()) return true;
        else if(p1.first.size() == p2.first.size()){
            if(p1.first < p2.first) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::map<std::string, int> words;

    std::string word;
    while(N--){
        std::cin >> word;
        if(word.size() >= M)
            words[word]++;
    }

    std::vector<std::pair<std::string,int>> words_result(words.begin(), words.end());
    std::sort(words_result.begin(), words_result.end(), cmp);

    for(std::pair<std::string, int> p : words_result){
        std::cout << p.first << "\n";
    }
}