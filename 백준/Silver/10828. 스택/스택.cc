#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> stack;
    std::string command;
    int input;
    while(N--){
        std::cin >> command;
        if(command == "push"){
            std::cin >> input;
            stack.push_back(input);
        }
        else if(command == "pop"){
            if(stack.empty())
                std::cout << -1 << "\n";
            else {
                std::cout << *(stack.end() - 1) << "\n";
                stack.erase(stack.end() - 1);
            }
        }
        else if(command == "size"){
            std::cout << stack.size() << "\n";
        }
        else if(command == "empty"){
            if(stack.empty()) std::cout << 1 << "\n";
            else std::cout << 0 << "\n";
        }
        else if(command == "top"){
            if(stack.empty())
                std::cout << -1 << "\n";
            else
                std::cout << *(stack.end()-1) << "\n";
        }
    }
}