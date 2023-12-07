#include <iostream>
#include <queue>

std::queue<int> q;
int N;

int main(){
    std::cin >> N;

    std::string cmd;
    int input;
    while(N--){
        std::cin >> cmd;
        if(cmd == "push"){
            std::cin >> input;
            q.push(input);
        }
        else if(cmd == "front")
            if(q.empty()) std::cout << -1 << "\n";
            else std::cout << q.front() << "\n";
        else if(cmd == "back")
            if(q.empty()) std::cout << -1 << "\n";
            else std::cout << q.back() << "\n";
        else if(cmd == "size")
            std::cout << q.size() << "\n";
        else if(cmd == "empty")
            std::cout << q.empty() << "\n";
        else{
            if(q.empty()) std::cout << -1 << "\n";
            else{
                std::cout << q.front() << "\n";
                q.pop();
            }
        }
    }
}