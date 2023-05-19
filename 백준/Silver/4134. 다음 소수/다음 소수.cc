#include <iostream>
#include <cmath>

bool isPrime(long long input){
    if(input <= 3) {
        if (input <= 1)
            return false;
        else
            return true;
    }
    else {
        for(long long i = 2; i <= sqrt(input); i++){
            if(input % i == 0)
                return false;
        }
    }
    return true;
}

int main() {
    long long N;
    std::cin >> N;
    while(N--){
        long long input;
        std::cin >> input;

        while(true){
            if(input == 0) {
                std::cout << 2 << "\n";
                break;
            }
            else if(isPrime(input)){
                std::cout << input << "\n";
                break;
            }
            input++;
        }
    }
}