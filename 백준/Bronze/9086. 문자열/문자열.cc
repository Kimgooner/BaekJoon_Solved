#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::string str;
    std::cin >> N;

    for(int i = 0;i < N; i++) {
        std::cin >> str;
        std::cout << str[0] << str[str.size()-1] << "\n";
    }
}
