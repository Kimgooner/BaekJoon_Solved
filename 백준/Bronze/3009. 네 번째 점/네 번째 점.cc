#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> x;
    std::vector<int> y;

    int xi, yi;
    for(int i = 0; i < 3; i++){
        std::cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }
    int res_x, res_y;
    std::sort(x.begin(), x.end());
    if(x[0] == x[1])
        res_x = x[2];
    if(x[1] == x[2])
        res_x = x[0];

    std::sort(y.begin(), y.end());
    if(y[0] == y[1])
        res_y = y[2];
    if(y[1] == y[2])
        res_y = y[0];

    std::cout << res_x << " " << res_y;
}
