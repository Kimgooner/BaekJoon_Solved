#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string str;
    std::cin >> str;

    int sum = 0;

    for(char c : str){
        if(c >= 'A' && 'C' >= c)
            sum += 3;
        if(c >= 'D' && 'F' >= c)
            sum += 4;
        if(c >= 'G' && 'I' >= c)
            sum += 5;
        if(c >= 'J' && 'L' >= c)
            sum += 6;
        if(c >= 'M' && 'O' >= c)
            sum += 7;
        if(c >= 'P' && 'S' >= c)
            sum += 8;
        if(c >= 'T' && 'V' >= c)
            sum += 9;
        if(c >= 'W' && 'Z' >= c)
            sum += 10;
    }
    std::cout << sum;
}
