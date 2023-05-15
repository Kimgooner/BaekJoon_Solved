#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string lhs, rhs;
    std::cin >> lhs >> rhs;

    int diff;
    bool isLhs = true;
    if(lhs.size() > rhs.size()) {
        diff = lhs.size() - rhs.size();
    }
    else {
        diff = rhs.size() - lhs.size();
        isLhs = false;
    }
    std::reverse(lhs.begin(), lhs.end());
    std::reverse(rhs.begin(), rhs.end());
    for(int i = 0; i < diff; i++){
        if(!isLhs)
            lhs += "0";
        else
            rhs += "0";
    }
    std::vector<char> result;
    int carry = 0;
    for(int i = 0; i < lhs.size(); i++){
        int sum = lhs[i] + rhs[i] + carry - (2*'0');
        if(sum > 9) {
            result.push_back(sum - 10 + '0');
            carry = 1;
        }
        else {
            result.push_back(sum + '0');
            carry = 0;
        }
    }
    if(carry == 1)
        result.push_back('1');

    std::reverse(result.begin(), result.end());
    for(char c : result)
        std::cout << c;
}