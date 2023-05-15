#include <iostream>

int main() {
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    int max_x, max_y;
    if(x > w-x)
        max_x = w-x;
    else
        max_x = x;

    if(y > h-y)
        max_y = h-y;
    else
        max_y = y;

    if(max_x > max_y)
        std::cout << max_y;
    else
        std::cout << max_x;
}