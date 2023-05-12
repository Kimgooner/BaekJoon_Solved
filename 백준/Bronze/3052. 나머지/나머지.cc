#include <iostream>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::vector<int> vec;
    int input;
    for(int i = 0; i < 10; i++){
        std::cin >> input;
        vec.push_back(input%42);
    }

    int cnt = 0;
    for(int i = 0; i < 42; i++){
        for(auto iter : vec){
            if(i == iter){
                cnt++;
                break;
            }
        }
    }
    std::cout << cnt;
}
