#include <iostream>

int A, B, C;
int cnt[10];

int main(){
    std::cin >> A >> B >> C;
    int res = A * B * C;

    while (res > 0){
        cnt[res % 10]++;
        res = res / 10;
    }

    for(int i = 0; i < 10; i++){
        std::cout << cnt[i] << std::endl;
    }
}