#include <iostream>
#include <map>

int N, M;
std::string site, pass;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    std::map<std::string, std::string> pwd;

    for(int i = 0; i < N; i++){
        std::cin >> site >> pass;
        pwd[site] = pass;
    }

    for(int i = 0; i < M; i++){
        std::cin >> site;
        std::cout << pwd[site] << "\n";
    }
}