#include <iostream>
#include <algorithm>
#include <set>

int main(){
    int N;
    std::cin >> N;

    std::set<std::string> dance;
    dance.insert("ChongChong");
    std::string name_f, name_s;
    while(N--){
        std::cin >> name_f >> name_s;
        auto find_f = dance.find(name_f);
        auto find_s = dance.find(name_s);
        if(find_f != dance.end() || find_s != dance.end()){
            dance.insert(name_f);
            dance.insert(name_s);
        }
    }
    std::cout << dance.size();
}