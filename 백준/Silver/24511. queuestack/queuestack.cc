#include <iostream>
#include <deque>

int N, M, input;
int type[100001];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        type[i] = input;
    }
    std::deque<int> elem;
    for(int i = 0; i < N; i++){
        std::cin >> input;
        if(!type[i]){
            elem.push_front(input);
        }
    }

    std::cin >> M;
    for(int i = 0; i < M; i++){
        std::cin >> input;
        elem.push_back(input);
    }

    while(M){
        std::cout << elem.front() << " ";
        elem.pop_front();
        M--;
    }
}