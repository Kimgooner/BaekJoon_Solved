#include <iostream>
#include <map>
int main() {
    int N;
    std::cin >> N;
    std::string name, log;
    std::map<std::string, std::string> people;
    for(int i = 0; i < N; i++){
        std::cin >> name >> log;
        people[name] = log;
    }
    for(auto iter = --people.end(); iter != --people.begin(); --iter){
        if(iter->second == "enter")
            std::cout << iter->first << "\n";
    }
}