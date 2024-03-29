#include <iostream>

int gcd(int a, int b){
    if(b == 0) return a;
    else {
        return gcd(b, a%b);
    }
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a,b) << "\n" << (a / gcd(a,b)) * b;
}