#include <iostream>
#include <cmath>

void move(int start, int dest){
    std::cout << start << " " << dest << "\n";
}

int hanoi(int N, int from, int by, int to){
    if(N == 0) return 1;
    hanoi(N-1, from, to, by);
    move(from, to);
    hanoi(N-1, by, from, to);
    return 1;
}

int main() {
    int N;
    std::cin >> N;
    int count = pow(2,N)-1;
    std::cout << count << "\n";
    hanoi(N, 1, 2, 3);
}