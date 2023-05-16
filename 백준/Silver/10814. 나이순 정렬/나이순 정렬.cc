#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int,std::pair<int,std::string>>& p1, std::pair<int,std::pair<int,std::string>>& p2){
    if(p1.second.first < p2.second.first) return true;
    else if(p1.second.first == p2.second.first)
        if(p1.first < p2.first) return true;
        else return false;
    else return false;
}

int main() {
    int N;
    std::cin >> N;

    int input;
    std::string str;
    std::vector<std::pair<int,std::pair<int,std::string>>> ids;
    for(int i = 0; i < N; i++){
        std::cin >> input >> str;
        std::pair<int,std::string> id = {input, str};
        ids.emplace_back(i, id);
    }
    std::sort(ids.begin(), ids.end(), cmp);

    for(std::pair<int,std::pair<int,std::string>> p : ids){
        std::cout << p.second.first << " " << p.second.second << "\n";
    }
}