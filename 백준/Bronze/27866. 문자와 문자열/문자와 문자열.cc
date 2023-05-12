#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string str;
    int N;
    std::cin >> str >> N;
    std::cout << str[N-1];
}
