#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<char> &str, int n, bool prt){
    if(n == 0) {
        if(prt)
            str.push_back('-');
        else
            str.push_back(' ');
    }
    else {
        if(prt){
            print(str, n-1, true);
            print(str, n-1, false);
            print(str, n-1, true);
        }
        else{
            for(int i = 0; i < pow(3,n); i++){
                str.push_back(' ');
            }
        }
    }
}

int main() {
    int input;
    while(true){
        std::vector<char> str;
        std::cin >> input;
        if(std::cin.eof())
            break;
        else{
            print(str, input, true);
        }
        std::string res(str.begin(), str.end());
        std::cout << res << "\n";
    }
}