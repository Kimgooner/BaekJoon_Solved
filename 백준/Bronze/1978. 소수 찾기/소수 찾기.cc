#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int input, cnt = 0, cnt_tmp;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        if(input == 1){
            continue;
        }
        cnt_tmp = 1;
        for(int j = 2; j < input; j++){
            if(input % j == 0) {
                cnt_tmp = 0;
                break;
            }
        }
        cnt += cnt_tmp;
    }
    std::cout << cnt;
}
