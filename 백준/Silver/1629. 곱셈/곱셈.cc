#include <iostream>

long long c_pow(long long c, int n, int div){
    if(c == 1) return 1;
    if(n == 1) return c % div;

    if(n % 2 == 0) return c_pow(c,n/2,div) * c_pow(c,n/2,div) % div;
    else return ((c_pow(c,n/2,div) * c_pow(c,n/2,div)) % div) * c % div;
}

int main(){
    int a,b,c;
    std::cin >> a >> b >> c;
    std::cout << c_pow(a,b,c);
}