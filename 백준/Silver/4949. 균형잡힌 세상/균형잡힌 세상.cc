#include <iostream>
#include <string>

int main() {
    while(true) {
        std::string input;
        std::getline(std::cin, input, '.');
        if(input[0] == '.' || (input[0] == 10 && input[1] == 0))
            break;
        else {
            char stack[101];
            int last = -1;

            bool correct = true;
            for(char c : input){
                if(c == '(') {
                    stack[++last] = c;
                }
                else if(c == ')') {
                    if(stack[last] != '(') {
                        correct = false;
                        break;
                    }
                    last--;
                }
                else if(c == '[') {
                    stack[++last] = c;
                }
                else if(c == ']') {
                    if(stack[last] != '[') {
                        correct = false;
                        break;
                    }
                    last--;
                }
            }
            if(correct && last == -1)
                std::cout << "yes" << "\n";
            else
                std::cout << "no" << "\n";
        }
    }
}