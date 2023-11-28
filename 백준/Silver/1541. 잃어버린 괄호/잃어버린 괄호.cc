#include <iostream>

int main(){
    std::string formula;
    std::cin >> formula;

    formula = formula + '+';

    int num = 0, res = 0;
    bool minus = false;
    for(char c : formula){
        if(c >= '0' && c <= '9'){
            num = num * 10 + (c - '0');
        }
        else{
            if(c == '+'){
                if(!minus) res += num;
                else res -= num;
            }
            else {
                if (!minus) {
                    res += num;
                    minus = true;
                }
                else {
                    res -= num;
                }
            }
            num = 0;
        }
    }
    std::cout << res;
}