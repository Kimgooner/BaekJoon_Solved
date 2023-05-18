#include <iostream>
#include <algorithm>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    std::string name;
    int id = 1;
    std::map<int, std::string> dic_id;
    std::map<std::string, int> dic_name;
    while(N--){
        std::cin >> name;
        dic_id[id] = name;
        dic_name[name] = id++;
    }

    std::string input;
    while(M--){
        std::cin >> input;
        if(input[0] >= '0' && '9' >= input[0]){
            std::cout << dic_id[std::stoi(input)] << "\n";
        }
        else
            std::cout << dic_name[input] << "\n";
    }
}