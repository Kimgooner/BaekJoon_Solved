#include <iostream>
#include <vector>

int main() {
    unsigned int N;
    int B, val;
    std::vector<char> vec;
    std::cin >> N >> B;

    while(1){
        val = N % B;
        if(val >= 0 && 9 >= val)
            vec.push_back(val+'0');
        if(val >= 10 && 35 >= val)
            vec.push_back(val+'A'-10);
        if(N < B)
            break;
        N = N / B;
    }
    for(auto iter = vec.end()-1; iter != vec.begin()-1; iter--)
        std::cout << *iter;
}
