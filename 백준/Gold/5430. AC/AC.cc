#include <iostream>
#include <deque>

void inputNums(std::deque<int> &dq, std::string &array){
    int sum = 0;
    for(char c : array){
        if(c >= '0' && '9' >= c){
            sum = sum*10 + (c - '0');
        }
        else if(c == ',' || c == ']'){
            if(sum != 0) {
                dq.push_back(sum);
                sum = 0;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    std::string command, array;
    int input, size;
    while(T--){
        std::cin >> command;
        std::cin >> size;
        std::cin >> array;

        std::deque<int> dq;
        inputNums(dq, array);

        bool isCorrect = true;
        int reverse = 0;
        for(char c : command){
            if(c == 'R'){
                reverse++;
            }
            else if(c == 'D'){
                if(size == 0){
                    isCorrect = false;
                    break;
                }
                if(reverse % 2 == 0){
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
                size--;
            }
        }

        if(isCorrect){
            if(size == 0)
                std::cout << "[]\n";
            else {
                std::cout << "[";
                for (int i = 0; i < size - 1; i++) {
                    if (reverse % 2 == 0) {
                        std::cout << dq.front() << ",";
                        dq.pop_front();
                    } else {
                        std::cout << dq.back() << ",";
                        dq.pop_back();
                    }
                }
                std::cout << dq.front() << "]\n";
            }
        }
        else
            std::cout << "error\n";
    }
}