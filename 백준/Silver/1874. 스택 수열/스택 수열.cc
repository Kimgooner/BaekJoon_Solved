#include <iostream>
#include <vector>

class stack {
private:
    int last = -1;
    int num = 1;
    int stack[300000];
public:
    void push(){
        stack[++last] = num++;
    }
    int pop(){
        if(last == -1)
            return -1;
        return stack[last--];
    }
    int top(){
        if(last == -1)
            return -1;
        return stack[last];
    }
    bool empty(){
        if(last != -1)
            return false;
        else return true;
    }
};

int main() {
    int N;
    std::cin >> N;

    int size = N;
    stack s;

    bool isCorrect = true;

    int prev = 0;
    int max;
    int input;
    std::vector<char> result;
    while(N){
        std::cin >> input;
        if(size == N){
            for(int i = 0; i < input; i++){
                s.push();
                result.push_back('+');
            }
            if(input != s.top()){
                isCorrect = false;
            }
            max = s.top();
            s.pop();
            result.push_back('-');
        }
        else{
            if(max < input && prev < input){
                for(int i = 0; i < input - max; i++){
                    s.push();
                    result.push_back('+');
                }
                if(input != s.top()){
                    isCorrect = false;
                }
                max = s.top();
                s.pop();
                result.push_back('-');
            }
            else if(prev > input && max > input){
                if(input != s.top()){
                    isCorrect = false;
                }
                else {
                    s.pop();
                    result.push_back('-');
                }
            }
            else
                isCorrect = false;
        }
        prev = input;
        N--;
    }
    if(isCorrect && s.empty()) {
        for (char c: result) {
            std::cout << c << "\n";
        }
    }
    else
        std::cout << "NO";
}