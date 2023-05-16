#include <iostream>
#include <vector>
#include <algorithm>

bool cmp (char a, char b){
    if(a > b) return true;
    else return false;
}

int main() {
    std::string str;
    std::cin >> str;

    std::vector<char> nums;
    for(char c : str){
        nums.push_back(c);
    }

    std::sort(nums.begin(), nums.end(), cmp);

    for(char c : nums)
        std::cout << c;
}