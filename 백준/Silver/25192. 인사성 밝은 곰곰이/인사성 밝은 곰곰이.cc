#include <iostream>
#include <algorithm>
#include <set>

int main(){
    int N;
    std::cin >> N;

    std::set<std::string> chatroom;
    std::string name;
    int cnt = 0;
    while(N--){
        std::cin >> name;
        if(name == "ENTER"){
            cnt += chatroom.size();
            chatroom.clear();
        }
        else
            chatroom.insert(name);
    }
    cnt += chatroom.size();
    std::cout << cnt;
}