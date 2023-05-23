#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    std::string input;
    while(T--){
        char stack[51];
        int last = - 1;
        std::cin >> input;
        for(char c : input){
            stack[++last] = c;
        }

        int flag = 0;
        bool answer = true;
        for(int i = last; i > -1; i--){
            if(stack[i] == ')')
                flag++;
            else if(stack[i] == '(' && flag == 0) {
                std::cout << "NO" << "\n";
                answer = false;
                break;
            }
            else if(stack[i] == '(' && flag > 0)
                flag--;
        }
        if(answer && flag == 0)
            std::cout << "YES" << "\n";
        else if(answer && flag != 0)
            std::cout << "NO" << "\n";
    }
}