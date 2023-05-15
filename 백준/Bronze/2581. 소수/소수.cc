#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    int prime_min = B, sum = 0, tmp;
    for(int i = A; i <= B; i++){
        if(i == 1)
            continue;
        tmp = i;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                tmp = 0;
                break;
            }
        }
        sum += tmp;
        if(tmp != 0 && tmp < prime_min)
            prime_min = tmp;
    }
    if(sum == 0)
        std::cout << -1;
    else
        std::cout << sum << "\n" << prime_min;
}