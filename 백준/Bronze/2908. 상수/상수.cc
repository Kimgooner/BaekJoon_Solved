#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string str1, str2;
    std::cin >> str1 >> str2;

    int n1 = (str1[2]-48)*100 + (str1[1]-48)*10 + (str1[0]-48);
    int n2 = (str2[2]-48)*100 + (str2[1]-48)*10 + (str2[0]-48);

    if(n1 > n2)
        std::cout << n1;
    else
        std::cout << n2;
}