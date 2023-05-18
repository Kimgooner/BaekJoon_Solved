#include <iostream>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::map<std::string, int> people;

    std::string input;
    while(N--){
        std::cin >> input;
        people[input]++;
    }

    int cnt = 0;
    while(M--){
        std::cin >> input;
        if(people[input] == 1)
            cnt++;
        people[input]++;
    }

    std::cout << cnt << "\n";
    for(auto& iter : people){
        if(iter.second == 2)
            std::cout << iter.first << "\n";
    }
}