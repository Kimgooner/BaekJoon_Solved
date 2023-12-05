#include <iostream>

int N;
int main(){
    std::cin >> N;

    int H, W, K;
    for(int i = 0; i < N; i++) {
        std::cin >> H >> W >> K;
        int floor = (K % H);
        if(floor == 0) floor = H;
        int room = (K / H);
        if(floor == H) room--;

        std::cout << floor;
        if(room+1 < 10) std::cout << "0" << room+1 << "\n";
        else std::cout << room+1 << "\n";
    }
}