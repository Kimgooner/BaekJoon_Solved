#include <iostream>
#include <cmath>

void conquer(int size, int x, int y, int r, int c, int cnt){
    if(size == 1){
        std::cout << (cnt*4) + c-y + (2*(r-x));
    }
    else{
        int length = (int)pow(2,size-1);
        if(r >= x && r <= x+length-1 && c >= y && c <= y+length-1) conquer(size-1, x, y, r, c, cnt*4+0);
        else if(r >= x && r <= x+length-1 && c >= y+length && c <= y+(2*length)-1) conquer(size-1, x, y+length, r, c, cnt*4+1);
        else if(r >= x+length && r <= x+(2*length)-1 && c >= y && c <= y+length-1) conquer(size-1, x+length, y, r, c, cnt*4+2);
        else conquer(size-1, x+length, y+length, r, c, cnt*4+3);
    }
}

int main(){
    int N;
    int r, c;
    std::cin >> N;
    std::cin >> r >> c;
    conquer(N, 0, 0, r, c, 0);
}