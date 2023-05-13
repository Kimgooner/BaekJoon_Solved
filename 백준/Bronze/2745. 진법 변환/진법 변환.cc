#include <iostream>
#include <vector>

int main() {
    std::string input;
    std::vector<int> vec;
    int N;
    std::cin >> input >> N;
    for(char c : input){
        for(auto& iter : vec){
            iter = iter*N;
        }
        if(c >= 'A' && 'Z' >= c)
            vec.push_back(c-'A'+10);
        else if(c >= '0' && '9' >= c)
            vec.push_back(c-'0');
    }
    int sum = 0;
    for(const auto iter : vec)
        sum += iter;
    std::cout << sum;
}