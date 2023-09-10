#include <iostream>
#include <stack>

int N, cmd, input;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    std::stack<int> stk;

    for(int i = 0; i < N; i++){
        std::cin >> cmd;
        switch (cmd) {
            case 1:
                std::cin >> input;
                stk.push(input);
                break;
            case 2:
                if(stk.empty()) std::cout << -1 << "\n";
                else {
                    std::cout << stk.top() << "\n";
                    stk.pop();
                }
                break;
            case 3:
                std::cout << stk.size() << "\n";
                break;
            case 4:
                if(stk.empty()) std::cout << 1 << "\n";
                else std::cout << 0 << "\n";
                break;
            case 5:
                if(stk.empty()) std::cout << -1 << "\n";
                else {
                    std::cout << stk.top() << "\n";
                }
                break;
        }
    }
}
