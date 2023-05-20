#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> sieve;
    for(int i = 2; i <= 2 * 123456; i++){
        sieve.push_back(i);
    }
    for(int& v : sieve) {
        for (int i = 2; i <= sqrt(2 * 123456); i++) {
            if (v % i == 0 && v != i) {
                v = 0;
            }
        }
    }
    int input;
    while(true){
        std::cin >> input;
        if(input == 0)
            break;
        int min = input + 1;
        int max = 2 * input;

        int cnt = 0;
        for(int i = min; i <= max; i++){
            if(sieve[i-2] != 0)
                cnt++;
        }
        std::cout << cnt << "\n";
    }
}